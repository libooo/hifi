//
//  JSONBreakableMarshal.h 
//  libraries/networking/src
//
//  Created by Stephen Birarda on 04/28/15.
//  Copyright 2015 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#ifndef hifi_JSONBreakableMarshal_h
#define hifi_JSONBreakableMarshal_h

#pragma once

#include <QtCore/QJsonValue>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariantMap>

class JSONBreakableMarshal {
public:
    static QByteArray toByteArray(const QJsonObject& jsonObject);
    static QJsonObject fromByteArray(const QByteArray& buffer);

    static void addInterpolationForKey(const QString& rootKey, const QString& interpolationKey,
                                       const QString& interpolationValue);
    static void removeInterpolationForKey(const QString& rootKey, const QString& interpolationKey); 
    
private:
    static void interpolate(QJsonValueRef currentValue, QString lastKey);
    
    static QVariantMap _interpolationMap;
};

#endif // hifi_JSONBreakableMarshal_h
