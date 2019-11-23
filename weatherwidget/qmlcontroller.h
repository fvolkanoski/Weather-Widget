#ifndef QMLCONTROLLER_H
#define QMLCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVariantMap>
#include <QJsonArray>
#include <QTimer>

#include "httprequestworker.h"

class qmlcontroller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString weatherIcon READ weatherIcon WRITE setWeatherIcon NOTIFY weatherIconChanged)
    Q_PROPERTY(QString weatherTemperature READ weatherTemperature WRITE setWeatherTemperature NOTIFY weatherTemperatureChanged)
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)

public:
    explicit qmlcontroller(QObject *parent = nullptr);

    QString weatherIcon() const
    {
        return m_weatherIcon;
    }

    QString weatherTemperature() const
    {
        return m_weatherTemperature;
    }

    QString city() const
    {
        return m_city;
    }

public slots:
    void setWeatherIcon(const QString &w)
    {
        if (w != m_weatherIcon)
        {
            m_weatherIcon = w;
            emit weatherIconChanged();
        }
    }

    void setWeatherTemperature(const QString &t)
    {
        if (t != m_weatherTemperature)
        {
            m_weatherTemperature = t;
            emit weatherTemperatureChanged();
        }
    }

    void setCity(QString city)
    {
        if (m_city == city)
            return;

        m_city = city;
        emit cityChanged(m_city);
    }

signals:
    void weatherIconChanged();
    void weatherTemperatureChanged();
    void cityChanged(QString city);

private slots:
    void handle_result(HttpRequestWorker *worker);

    // Calls the weather api.
    void callApi();

private:
    // Parses the weather api response to separate the weather data.
    void parseApiResponse(QByteArray apiResponse);

    QString m_weatherIcon;
    QString m_weatherTemperature;
    QString m_city;
};

#endif // QMLCONTROLLER_H
