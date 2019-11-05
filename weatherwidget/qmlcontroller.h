#ifndef QMLCONTROLLER_H
#define QMLCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVariantMap>

#include "httprequestworker.h"

class qmlcontroller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString weatherIcon READ weatherIcon WRITE setWeatherIcon NOTIFY weatherIconChanged)
public:
    explicit qmlcontroller(QObject *parent = nullptr);

    // Calls the weather api.
    Q_INVOKABLE void callApi();

    void setWeatherIcon(const QString &w) {
            if (w != m_weatherIcon) {
                m_weatherIcon = w;
                emit weatherIconChanged();
            }
        }
        QString weatherIcon() const {
            return m_weatherIcon;
        }

signals:
        void weatherIconChanged();

private slots:
    void handle_result(HttpRequestWorker *worker);

private:
    // Parses the weather api response to separate the weather data.
    void parseApiResponse(QByteArray apiResponse);

    QString m_weatherIcon;
};

#endif // QMLCONTROLLER_H
