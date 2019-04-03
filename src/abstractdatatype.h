#ifndef ABSTRACTDATATYPE_H
#define ABSTRACTDATATYPE_H

#include <QMetaType>

#include <memory>

class AbstractDataType
{
public:
    virtual ~AbstractDataType() = default;

    virtual QByteArray GetData() const = 0;
    virtual QString GetIdentifier() const = 0;
};
using AbstractDataTypeSharedPtr = std::shared_ptr<AbstractDataType>;
Q_DECLARE_METATYPE(AbstractDataTypeSharedPtr)

#endif // ABSTRACTDATATYPE_H
