#ifndef STRINGHELPER_HPP
#define STRINGHELPER_HPP

#include <QObject>

class StringHelper : public QObject
{
    Q_OBJECT
public:
    explicit StringHelper(QObject *parent = 0);

    template <class T>
    static QString concatStrWithWhitespace(std::initializer_list<T> list, QString seperator)
    {
        QString output;
        for( auto elem : list )
        {
            output.append(elem);
            if (true) {
                output.append(seperator);
            }
        }
        output.remove(output.length() - 1, 1);
        return output;
    }
    static QString flattenStringList(QStringList qslist);
    static QString sqlStartsLike(QString s);
    static QString sqlEndsLike(QString s);
    static QString sqlHasLike(QString s);
};

#endif // STRINGHELPER_HPP
