#include "connection.hpp"

#include "../helpers/filehelper.hpp"
#include "../helpers/stringhelper.hpp"

Connection *Connection::m_connection = NULL;

Connection::Connection(QObject *parent) : QObject(parent)
{
    QString db_filename = "db.sqlite3";
    if (!FileHelper::fileExists("db.sqlite3"))
    {
        Connection::m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName(db_filename);
        m_db.open();
        qDebug() << "Database created successfully!";
        QStringList qList = FileHelper::fileToString("../database.sql");
        foreach (QString q, qList) {
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
    QStringList qList = FileHelper::fileToString("../seeds.sql");
    foreach (QString q, qList) {
        m_db.exec(q);
    }
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
        s->setStatus(q.value(9).toString());
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
        s->setStatus(q.value(9).toString());
        s->setSendingOffice(getOffice(q.value(10).toInt()));
        s->setReceivingOffice(getOffice(q.value(11).toInt()));
        shipments.append(s);
    }
    if (shipments.isEmpty())
        return new Shipment();
    return shipments.first();
}

City *Connection::updateCity(City *c)
{
    QSqlQuery q;
    q.prepare("update cities set name = ? where id = ?");
    q.bindValue(0, c->getName());
    q.bindValue(1, c->getId());
    q.exec();
    return c;
}

Customer *Connection::updateCustomer(Customer *c)
{
    QSqlQuery q;
    q.prepare("update customers set tc = ?, name = ?, surname = ?,\
              phone = ?, city_id = ?, address = ? where id = ?"\
                                                              );
    q.bindValue(0, c->getTc());
    q.bindValue(1, c->getName());
    q.bindValue(2, c->getSurname());
    q.bindValue(3, c->getPhone());
    q.bindValue(4, c->getCity()->getId());
    q.bindValue(5, c->getAddress());
    q.bindValue(6, c->getId());
    q.exec();
    return c;
}

Distance *Connection::updateDistance(Distance *d)
{
    QSqlQuery q;
    q.prepare("update distances set first_office_id = ?, second_office_id = ?, \
              value = ? where id = ?"\
                                    );
    q.bindValue(0, d->getFirstOffice()->getId());
    q.bindValue(1, d->getSecondOffice()->getId());
    q.bindValue(2, d->getValue());
    q.bindValue(3, d->getId());
    q.exec();
    return d;
}

Office *Connection::updateOffice(Office *o)
{
    QSqlQuery q;
    q.prepare("update offices set name = ?, city_id = ?, address = ? where id = ?");
    q.bindValue(0, o->getName());
    q.bindValue(1, o->getCity()->getId());
    q.bindValue(2, o->getAddress());
    q.bindValue(3, o->getId());
    q.exec();
    return o;
}

Shipment *Connection::updateShipment(Shipment *s)
{
    QSqlQuery q;
    q.prepare("update shipments set length = ?, width = ?, height = ?,\
              weight = ?, sending_customer_id = ?, receiving_customer_id = ?,\
              payment_type = ?, amount = ?, status = ?, sending_office_id = ?, \
              receiving_office_id = ? where id = ?"\
                                                  );
    q.bindValue(0, s->getLength());
    q.bindValue(1, s->getWeight());
    q.bindValue(2, s->getHeight());
    q.bindValue(3, s->getWeight());
    q.bindValue(4, s->getSendingCustomer()->getId());
    q.bindValue(5, s->getReceivingCustomer()->getId());
    q.bindValue(6, s->getPaymentType());
    q.bindValue(7, s->getAmount());
    q.bindValue(8, s->getStatus());
    q.bindValue(9, s->getSendingOffice()->getId());
    q.bindValue(10, s->getReceivingOffice()->getId());
    q.bindValue(11, s->getId());
    q.exec();
    return s;
}

CityList Connection::getCities(QString value)
{
    QSqlQuery q;
    q.prepare("select * from cities where name like ?");
    q.bindValue(0, StringHelper::sqlHasLike(value));
    q.exec();
    CityList cities;
    while (q.next()) {
        City *c = new City();
        c->setId(q.value(0).toInt());
        c->setName(q.value(1).toString());
        cities.append(c);
    }
    if (cities.isEmpty())
        cities.append(new City);
    return cities;
}

CustomerList Connection::getCustomers(QString value)
{
    QSqlQuery q;
    q.prepare("select * from customers where id = ? or tc like ?\
              or name like ? or surname like ? or phone like ?\
              or city_id = ? or address like ?"\
                                 );
    q.bindValue(0, value.toInt()); // id
    q.bindValue(1, StringHelper::sqlHasLike(value)); // tc
    q.bindValue(2, StringHelper::sqlHasLike(value)); // name
    q.bindValue(3, StringHelper::sqlHasLike(value)); // surname
    q.bindValue(4, StringHelper::sqlHasLike(value)); // phone
    q.bindValue(5, StringHelper::sqlHasLike(value)); // city_id
    q.bindValue(6, StringHelper::sqlHasLike(value)); // address
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
    if (customers.isEmpty())
        customers.append(new Customer);
    return customers;
}

DistanceList Connection::getDistances()
{
    DistanceList distances;
    // TO DO
    return distances;
}

OfficeList Connection::getOffices(QString value)
{
    QSqlQuery q;
    q.prepare("select * from offices where name like ?");
    q.bindValue(0, StringHelper::sqlHasLike(value));
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
    if (offices.isEmpty())
        offices.append(new Office);
    return offices;
}

ShipmentList Connection::getShipments()
{
    ShipmentList shipments;
    // TO DO
    return shipments;
}


City *Connection::createCity(City *c)
{
    QSqlQuery q;
    q.prepare("insert into cities (name) values (?)");
    q.bindValue(0, c->getName());
    if (q.exec()){
        return c;
    }
    else {
        return new City;
    }
}

Customer *Connection::createCustomer(Customer *c)
{
    QSqlQuery q;
    q.prepare("insert into customers (tc, name, surname, phone, city_id, address)\
              values(?, ?, ?, ?, ?, ?) "\
              );
    q.bindValue(0, c->getTc());
    q.bindValue(1, c->getName());
    q.bindValue(2, c->getSurname());
    q.bindValue(3, c->getPhone());
    q.bindValue(4, c->getCity()->getId());
    q.bindValue(5, c->getAddress());
    if (q.exec()) {
        return c;
    }
    else {
        return new Customer;
    }
}

Distance *Connection::createDistance(Distance *d)
{
    QSqlQuery q;
    q.prepare("insert into distances (first_office_id, second_office_id, value)\
              values(?, ?, ?)"\
              );
    q.bindValue(0, d->getFirstOffice()->getId());
    q.bindValue(1, d->getSecondOffice()->getId());
    q.bindValue(2, d->getValue());
    if (q.exec()) {
        return d;
    }
    else {
        return new Distance;
    }
}

Office *Connection::createOffice(Office *o)
{
    QSqlQuery q;
    q.prepare("insert into offices (name, city_id, address) values (?, ?, ?)");
    q.bindValue(0, o->getName());
    q.bindValue(1, o->getCity()->getId());
    q.bindValue(2, o->getAddress());
    if (q.exec()) {
        return o;
    }
    else {
        return new Office;
    }
}

Shipment *Connection::createShipment(Shipment *s)
{
    QSqlQuery q;
    q.prepare("insert into shipments (length, width, height, weight,\
              sending_customer_id, receiving_customer_id, payment_type,\
              amount, status, sending_office_id, receiving_office_id)"\
            );
    q.bindValue(0, s->getLength());
    q.bindValue(1, s->getWidth());
    q.bindValue(2, s->getHeight());
    q.bindValue(3, s->getWeight());
    q.bindValue(4, s->getSendingCustomer()->getId());
    q.bindValue(5, s->getReceivingCustomer()->getId());
    q.bindValue(6, s->getPaymentType());
    q.bindValue(7, s->getAmount());
    q.bindValue(8, s->getStatus());
    q.bindValue(9, s->getSendingOffice()->getId());
    q.bindValue(10, s->getReceivingOffice()->getId());
    if (q.exec()) {
        return s;
    }
    else {
        return new Shipment;
    }
}

