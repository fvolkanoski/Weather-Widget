#ifndef HTTPREQUESTWORKER_H
#define HTTPREQUESTWORKER_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkReply>


/* \brief Holds the enumeration for the variable layout.
 *
*/
enum HttpRequestVarLayout {
    NOT_SET,
    ADDRESS,
    URL_ENCODED,
    MULTIPART
};


/* \brief
 *
*/
class HttpRequestInputFileElement {

public:
    QString variable_name;
    QString local_filename;
    QString request_filename;
    QString mime_type;

};

/* \brief The request input class, holds the input parameters for the request.
 *
*/
class HttpRequestInput {

public:

    QString url_str;
    QString http_method;
    HttpRequestVarLayout var_layout;
    QMap<QString, QString> vars;
    QList<HttpRequestInputFileElement> files;

    /* \brief
     *
    */
    HttpRequestInput();

    /* \brief
     *
     * @param v_url_str
     * @param v_http_method
    */
    HttpRequestInput(QString v_url_str, QString v_http_method);

    /* \brief
     *
    */
    void initialize();

    /* \brief
     *
     * @param key
     * @param value
    */
    void add_var(QString key, QString value);

    /* \brief
     *
     * @param variable_name
     * @param local_filename
     * @param request_filename
     * @param mime_type
    */
    void add_file(QString variable_name, QString local_filename, QString request_filename, QString mime_type);

};


class HttpRequestWorker : public QObject {
    Q_OBJECT

public:
    QByteArray response;
    QNetworkReply::NetworkError error_type;
    QString error_str;

    explicit HttpRequestWorker(QObject *parent = 0);

    /* \brief
     *
     * @param attribute_name
     * @param input
    */
    QString http_attribute_encode(QString attribute_name, QString input);

    /* \brief
     *
     * @param input
    */
    void execute(HttpRequestInput *input);

signals:
    /* \brief
     *
     * @param worker
    */
    void on_execution_finished(HttpRequestWorker *worker);

private:
    QNetworkAccessManager *manager;

private slots:
    /* \brief
     *
     * @param reply
    */
    void on_manager_finished(QNetworkReply *reply);

};

#endif // HTTPREQUESTWORKER_H
