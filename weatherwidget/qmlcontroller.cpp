#include "qmlcontroller.h"

qmlcontroller::qmlcontroller(QObject *parent) : QObject(parent)
{
    this->setCity("Skopje,mk");
    this->callApi();

    QTimer *apiTimer = new QTimer(this);
    connect(apiTimer, SIGNAL(timeout()), this, SLOT(callApi()));
    apiTimer->start(10000);
}

void qmlcontroller::callApi()
{
    QString url_str = "http://api.openweathermap.org/data/2.5/weather";

    HttpRequestInput input(url_str, "GET");

    input.add_var("q", this->city());
    input.add_var("APPID", "3f43d9bc64d2298096180a2d3f6d9965");
    input.add_var("units", "metric");

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
    QJsonObject apiObj = apiRes.object();
    QJsonObject::iterator apiObjIt;

    for (apiObjIt = apiObj.begin(); apiObjIt != apiObj.end(); apiObjIt++)
    {
        if(apiObjIt.key() == "main")
        {
            QJsonObject o1 = apiObjIt.value().toObject();
            QJsonObject::iterator it1 = o1.begin();
            for(it1=o1.begin();it1!=o1.end();it1++)
            {
                qDebug() << " Key =" << it1.key();
                if (it1.value().isDouble())
                {
                    qDebug() << " Value =" << it1.value().toDouble() <<endl;
                }
                if(it1.key() == "temp")
                {
                    this->setWeatherTemperature(QString::number(std::floor(it1.value().toDouble())));
                }
            }
        }
        if(apiObjIt.key() == "weather")
        {
            QJsonArray jsonArray = apiObjIt.value().toArray();

            foreach (const QJsonValue & value, jsonArray)
            {
                QJsonObject obj = value.toObject();
                qDebug() << "===================";
                qDebug() << obj.value("description");
                qDebug() << "===================";
                qDebug() << obj.value("icon");
                this->setWeatherIcon(obj.value("icon").toString());
                qDebug() << "===================";
                qDebug() << obj.value("main");
                qDebug() << "===================";
            }
        }
    }
}
