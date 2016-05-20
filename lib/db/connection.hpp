#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QList>

#include "../models/city.hpp"
#include "../models/customer.hpp"
#include "../models/distance.hpp"
#include "../models/office.hpp"
#include "../models/shipment.hpp"

typedef QList<City*> CityList;
typedef QList<Customer*> CustomerList;
typedef QList<Distance*> DistanceList;
typedef QList<Office*> OfficeList;
typedef QList<Shipment*> ShipmentList;

class Connection : public QObject
{
    Q_OBJECT

private:
    explicit Connection(QObject *parent = 0);
    static Connection *m_connection;
    QSqlDatabase m_db;
    void seed();

public:
    static Connection *getConnection();
signals:

public slots:
    CityList getAllCities();
    CustomerList getAllCustomers();
    DistanceList getAllDistances();
    OfficeList getAllOffices();
    ShipmentList getAllShipments();

    City *getCity(int id);
    Customer *getCustomer(int id);
    Distance *getDistance(int id);
    Office *getOffice(int id);
    Shipment *getShipment(int id);

    City *updateCity(City *c);
    Customer *updateCustomer(Customer *c);
    Distance *updateDistance(Distance *d);
    Office *updateOffice(Office *o);
    Shipment *updateShipment(Shipment *s);

    CustomerList getCustomers(QString value);
};

#endif // CONNECTION_HPP
