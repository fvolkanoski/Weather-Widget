#ifndef QMLCONTROLLER_H
#define QMLCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVariantMap>
#include <QJsonArray>
#include <QTimer>
#include <QWindow>

#include "constants.h"
#include "httprequestworker.h"

/* \brief The QmlController class.
 *
 * The QMLController class is responsible for calling the REST API for weather information
 * and controlling the UI using the properties connected to the UI labels.
*/
class QmlController : public QObject {
    Q_OBJECT

    /*
     * @param weatherIcon Contains the link to the current weather icon to be displayed on the UI.
    */
    Q_PROPERTY(QString weatherIcon READ weatherIcon WRITE setWeatherIcon NOTIFY weatherIconChanged)

    /*
     * @param weatherTemparature Contains information about the current temperature, this var is connected
     *                           to the UI temperature label.
    */
    Q_PROPERTY(QString weatherTemperature READ weatherTemperature WRITE setWeatherTemperature NOTIFY weatherTemperatureChanged)

    /*
     * @param city Contains information about the city for which the temperature is displayed, this var is
                   connected to the UI city label.
    */
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)

public:
    /* \brief The QmlController class default constructor.
     *
    */
    explicit QmlController(QObject *parent = nullptr);

    /* \brief Getter for the m_weatherIcon var.
     *
    */
    QString weatherIcon() const {
        return m_weatherIcon;
    }

    /* \brief Getter for the m_weatherTemperature var.
     *
    */
    QString weatherTemperature() const {
        return m_weatherTemperature;
    }

    /* \brief Getter for the m_city var.
     *
    */
    QString city() const {
        return m_city;
    }

public slots:
    /* \brief Setter for the m_weatherIcon var.
     *
     * @param &w The weather icon path/link/location.
    */
    void setWeatherIcon(const QString &w) {
        if (w != m_weatherIcon) {
            m_weatherIcon = w;
            emit weatherIconChanged();
        }
    }

    /* \brief Setter for the m_weatherTemperature var.
     *
     * @param &t The current weather temperature.
    */
    void setWeatherTemperature(const QString &t) {
        if (t != m_weatherTemperature) {
            m_weatherTemperature = t;
            emit weatherTemperatureChanged();
        }
    }

    /* \brief Setter for the m_city var.
     *
     * @param &c The current city that the temperature information
     *           is displayed about.
    */
    void setCity(const QString &c) {
        if (m_city == c)
            return;

        m_city = c;
        emit cityChanged(m_city);
    }

signals:
    /* \brief Called when the m_weatherIcon variable is changed.
     *        It is used for the weatherIcon property.
     *
    */
    void weatherIconChanged();

    /* \brief Called when the m_weatherTemperature variable is changed.
     *        It is used for the weatherTemperature property.
     *
    */
    void weatherTemperatureChanged();

    /* \brief Called when the m_city variable is changed.
     *        It is used for the city property.
     *
    */
    void cityChanged(QString city);

private slots:
    /* \brief Used to handle the result that the REST API provides.
     *
    */
    void handle_result(HttpRequestWorker *worker);

    /* \brief Calls the REST API to provide weather information about
     *        the currently selected city.
     *
    */
    void callApi();

private:
    /* \brief Parses the REST API response to pull out weather data.
     *
    */
    void parseApiResponse(QByteArray apiResponse);

    /*
     * @param m_weatherIcon Used to hold the weather icon path/link/location.
    */
    QString m_weatherIcon;

    /*
     * @param m_weatherTemperature Used to hold the weather temperature.
    */
    QString m_weatherTemperature;

    /*
     * @param m_city Used to hold the current city name.
    */
    QString m_city;
};

#endif // QMLCONTROLLER_H
