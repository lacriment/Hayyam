#include "connection.hpp"
#include "../helpers/filehelper.hpp"

Connection *Connection::m_connection = NULL;

Connection::Connection(QObject *parent) : QObject(parent)
{
    FileHelper helper;
    QString db_filename = "db.sqlite3";
    if (!helper.fileExists("db.sqlite3"))
    {
        Connection::m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName(db_filename);
        qDebug() << "Database created successfully!";
        QString q = helper.fileToString("database.sql");
        m_db.open();
        qDebug() << q;
        m_db.exec(q);
        seed();
    }
    else {
        Connection::m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName(db_filename);
        m_db.open();
    }
}

void Connection::seed()
{
   FileHelper helper;
   m_db.exec(helper.fileToString("seeds.sql"));
}

Connection *Connection::getConnection()
{
    if (m_connection == NULL) {
        m_connection = new Connection;
    }
    return m_connection;
}
