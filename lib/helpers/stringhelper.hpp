#ifndef STRINGHELPER_HPP
#define STRINGHELPER_HPP

#include <QObject>

class StringHelper : public QObject
{
    Q_OBJECT
public:
    explicit StringHelper(QObject *parent = 0);

    template <class T>
    static QString concatStrWithWhitespace( std::initializer_list<T> list )
    {
        QString output;
        for( auto elem : list )
        {
            output.append(elem);
            if (true) {
                output.append(" ");
            }
        }
        output.remove(output.length() - 1, 1);
        return output;
    }
};

#endif // STRINGHELPER_HPP
