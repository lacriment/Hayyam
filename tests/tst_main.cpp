#include <QString>
#include <QtTest>

class MainTest : public QObject
{
    Q_OBJECT

public:
    MainTest();

private Q_SLOTS:
    void testCase1();
};

MainTest::MainTest()
{
}

void MainTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(MainTest)

#include "tst_main.moc"
