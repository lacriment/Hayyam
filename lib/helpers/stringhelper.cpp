#include "stringhelper.hpp"

StringHelper::StringHelper(QObject *parent) : QObject(parent)
{

}

QString StringHelper::flattenStringList(QStringList qslist)
{
    QString out = "";
    std::for_each(qslist.begin(), qslist.end(), [&out] (QString s) { out.append(s); });
    return out;
}
