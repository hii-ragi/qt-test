#include <QApplication>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QTimer>
#include <QtGlobal>

#include <cstdio>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStringList args = app.arguments();
    const bool smokeTest = args.removeAll(QStringLiteral("--smoke-test")) > 0;
    const QString kind = args.size() > 1 ? args.at(1) : QStringLiteral("plain");
    if (args.size() > 2 || (kind != "plain" && kind != "line" && kind != "text")) {
        std::fprintf(stderr, "Usage: ime-test [plain|line|text] [--smoke-test]\n");
        return 1;
    }

    std::unique_ptr<QWidget> input;
    if (kind == "line") {
        input = std::make_unique<QLineEdit>();
    } else if (kind == "text") {
        input = std::make_unique<QTextEdit>();
    } else {
        input = std::make_unique<QPlainTextEdit>();
    }

    input->setWindowTitle(QStringLiteral("Qt Input Test - %1 - Qt %2")
                              .arg(input->metaObject()->className(), qVersion()));
    input->resize(640, kind == "line" ? 80 : 360);
    input->show();
    input->setFocus();
    // CI checks widget creation and the event loop, not actual IME input.
    if (smokeTest) QTimer::singleShot(0, &app, &QApplication::quit);
    return app.exec();
}
