#include "qmlcontroller.h"

qmlcontroller::qmlcontroller(QObject *parent) : QObject(parent)
{

}

void qmlcontroller::callApi()
{
    QString url_str = "http://api.openweathermap.org/data/2.5/weather";

    HttpRequestInput input(url_str, "GET");

    input.add_var("q", "London,uk");
    input.add_var("APPID", "3f43d9bc64d2298096180a2d3f6d9965");

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
    worker->execute(&input);
}

void qmlcontroller::handle_result(HttpRequestWorker *worker)
{
    QString msg;

    if (worker->error_type == QNetworkReply::NoError)
    {
        // Communication was successful.
        msg = "Success - Response: " + worker->response;
        this->parseApiResponse(worker->response);
    }
    else
    {
        // An error occurred.
        msg = "Error: " + worker->error_str;
    }

    qDebug() << msg;
}

void qmlcontroller::parseApiResponse(QByteArray apiResponse)
{
    // Create a json document from the api response.
    QJsonDocument apiRes = QJsonDocument::fromJson(apiResponse);

    // Create a json object from the json document.
    QJsonObject jObject = apiRes.object();

    QVariantMap varMap = jObject.toVariantMap();

    this->setWeatherIcon(varMap.value("weather").toString());
    qDebug() << "";

    QVariant test = varMap.value("weather");

   // qDebug() << test[0].
}
