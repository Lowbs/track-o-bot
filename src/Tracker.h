#pragma once

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QSettings>
#include <QSslError>
#include <QJsonObject>

class Tracker : public QObject
{
  Q_OBJECT

DEFINE_SINGLETON( Tracker )

private:
  QNetworkAccessManager mNetworkManager;
  QSettings mSettings;

  QNetworkReply* AuthPostJson( const QString& path, const QByteArray& data );

private slots:
  void CreateAndStoreAccountHandleReply();
  void OpenProfileHandleReply();

  void SSLErrors( QNetworkReply *reply, const QList<QSslError>& errors );

  QNetworkRequest CreateTrackerRequest( const QString& path );

public:
  bool IsAccountSetUp() const;

  void UploadResult( const QJsonObject& result );
  void CreateAndStoreAccount();
  void OpenProfile();
  void EnsureAccountIsSetUp();

  QString Username() const;
  void SetUsername( const QString& username );

  QString Password() const;
  void SetPassword( const QString& password );

  QString WebserviceURL();
  QString WebserviceURL( const QString& path );
  void SetWebserviceURL( const QString& webserviceUrl );

signals:
  void AccountCreated();
  void UploadResultFailed( const QJsonObject& result, int errorCode );
  void UploadResultSucceeded( const QJsonObject& result );

};

