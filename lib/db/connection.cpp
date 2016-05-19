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
        m_db.open();
        qDebug() << "Database created successfully!";
        QStringList qList = helper.fileToString("../database.sql");
        foreach (QString q, qList) {
            qDebug() << q;
            m_db.exec(q);
        }
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
   //m_db.exec(helper.fileToString("seeds.sql"));
}

Connection *Connection::getConnection()
{
    if (m_connection == NULL) {
        m_connection = new Connection;
    }
    return m_connection;
}

CityList Connection::getAllCities()
{
    QSqlQuery q;
    q.prepare("select * from cities");
    q.exec();
    CityList cities;
    while (q.next()) {
        City *c = new City();
        c->setId(q.value(0).toInt());
        c->setName(q.value(1).toString());
        cities.append(c);
    }
    return cities;
}

CustomerList Connection::getAllCustomers()
{
    QSqlQuery q;
    q.prepare("select * from customers");
    q.exec();
    CustomerList customers;
    while (q.next()) {
        Customer *c = new Customer();
        c->setId(q.value(0).toInt());
        c->setTc(q.value(1).toString());
        c->setName(q.value(2).toString());
        c->setSurname(q.value(3).toString());
        c->setPhone(q.value(4).toString());
        c->setCity(getCity(q.value(5).toInt()));
        c->setAddress(q.value(6).toString());
        customers.append(c);
    }
    return customers;
}

DistanceList Connection::getAllDistances()
{
    QSqlQuery q;
    q.prepare("select * from distances");
    q.exec();
    DistanceList distances;
    while (q.next()) {
        Distance *d = new Distance();
        d->setId(q.value(0).toInt());
        d->setFirstOffice(getOffice(q.value(1).toInt()));
        d->setSecondOffice(getOffice(q.value(2).toInt()));
        d->setValue(q.value(3).toDouble());
        distances.append(d);
    }
    return distances;
}

OfficeList Connection::getAllOffices()
{
    QSqlQuery q;
    q.prepare("select * from offices");
    q.exec();
    OfficeList offices;
    while (q.next()) {
        Office *o = new Office();
        o->setId(q.value(0).toInt());
        o->setName(q.value(1).toString());
        o->setCity(getCity(q.value(2).toInt()));
        o->setAddress(q.value(3).toString());
        offices.append(o);
    }
    return offices;
}

ShipmentList Connection::getAllShipments()
{
    QSqlQuery q;
    q.prepare("select * from shioments");
    q.exec();
    ShipmentList shipments;
    while (q.next()) {
        Shipment *s = new Shipment();
        s->setId(q.value(0).toInt());
        s->setLength(q.value(1).toInt());
        s->setWidth(q.value(2).toInt());
        s->setHeight(q.value(3).toInt());
        s->setWeight(q.value(4).toInt());
        s->setSendingCustomer(getCustomer(q.value(5).toInt()));
        s->setReceivingCustomer(getCustomer(q.value(6).toInt()));
        s->setPaymentType(q.value(7).toInt());
        s->setAmount(q.value(8).toDouble());
        s->setStatus(q.value(9).toInt());
        s->setSendingOffice(getOffice(q.value(10).toInt()));
        s->setReceivingOffice(getOffice(q.value(11).toInt()));
        shipments.append(s);
    }
    return shipments;
}

City *Connection::getCity(int id)
{
    QSqlQuery q;
    q.prepare("select * from cities where id = ?");
    q.bindValue(0, id);
    q.exec();
    CityList cities;
    while (q.next()) {
        City *c = new City();
        c->setId(q.value(0).toInt());
        c->setName(q.value(1).toString());
        cities.append(c);
    }
    return cities.first();
}

Customer *Connection::getCustomer(int id)
{
    QSqlQuery q;
    q.prepare("select * from customers where id = ?");
    q.bindValue(0, id);
    q.exec();
    CustomerList customers;
    while (q.next()) {
        Customer *c = new Customer();
        c->setId(q.value(0).toInt());
        c->setTc(q.value(1).toString());
        c->setName(q.value(2).toString());
        c->setSurname(q.value(3).toString());
        c->setPhone(q.value(4).toString());
        c->setCity(getCity(q.value(5).toInt()));
        c->setAddress(q.value(6).toString());
        customers.append(c);
    }
    return customers.first();
}

Distance *Connection::getDistance(int id)
{
    QSqlQuery q;
    q.prepare("select * from distances where id = ?");
    q.bindValue(0, id);
    q.exec();
    DistanceList distances;
    while (q.next()) {
        Distance *d = new Distance();
        d->setId(q.value(0).toInt());
        d->setFirstOffice(getOffice(q.value(1).toInt()));
        d->setSecondOffice(getOffice(q.value(2).toInt()));
        d->setValue(q.value(3).toDouble());
        distances.append(d);
    }
    return distances.first();
}

Office *Connection::getOffice(int id)
{
    QSqlQuery q;
    q.prepare("select * from offices where id = ?");
    q.bindValue(0, id);
    q.exec();
    OfficeList offices;
    while (q.next()) {
        Office *o = new Office();
        o->setId(q.value(0).toInt());
        o->setName(q.value(1).toString());
        o->setCity(getCity(q.value(2).toInt()));
        o->setAddress(q.value(3).toString());
        offices.append(o);
    }
    return offices.first();
}

Shipment *Connection::getShipment(int id)
{
    QSqlQuery q;
    q.prepare("select * from shipments where id = ?");
    q.bindValue(0, id);
    q.exec();
    ShipmentList shipments;
    while (q.next()) {
        Shipment *s = new Shipment();
        s->setId(q.value(0).toInt());
        s->setLength(q.value(1).toInt());
        s->setWidth(q.value(2).toInt());
        s->setHeight(q.value(3).toInt());
        s->setWeight(q.value(4).toInt());
        s->setSendingCustomer(getCustomer(q.value(5).toInt()));
        s->setReceivingCustomer(getCustomer(q.value(6).toInt()));
        s->setPaymentType(q.value(7).toInt());
        s->setAmount(q.value(8).toDouble());
        s->setStatus(q.value(9).toInt());
        s->setSendingOffice(getOffice(q.value(10).toInt()));
        s->setReceivingOffice(getOffice(q.value(11).toInt()));
        shipments.append(s);
    }
    return shipments.first();
}

City *Connection::updateCity(City *city)
{
    QSqlQuery q;
    return city;
}

Customer *Connection::updateCustomer(Customer *customer)
{

}

Distance *Connection::updateDistance(Distance *distance)
{

}

Office *Connection::updateOffice(Office *office)
{

}

Shipment *Connection::updateShipment(Shipment *shipment)
{

}
