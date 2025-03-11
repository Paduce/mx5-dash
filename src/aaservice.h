#ifndef AASERVICE_H
#define AASERVICE_H

#include <QObject>
#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>
#include <QTimer>
#include <memory>

// Forward declaration of Headunit class
class Headunit;

class AAService : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ videoSurface WRITE setVideoSurface NOTIFY videoSurfaceChanged)
    Q_PROPERTY(int status READ status NOTIFY statusChanged)
    Q_PROPERTY(int videoWidth READ videoWidth NOTIFY videoResized)
    Q_PROPERTY(int videoHeight READ videoHeight NOTIFY videoResized)
    Q_PROPERTY(int outputWidth MEMBER m_outputWidth NOTIFY outputResized)
    Q_PROPERTY(int outputHeight MEMBER m_outputHeight NOTIFY outputResized)

public:
    explicit AAService(QObject *parent = nullptr);
    virtual ~AAService();

    QAbstractVideoSurface* videoSurface() const;
    void setVideoSurface(QAbstractVideoSurface* surface);

    int status() const;
    int videoWidth() const;
    int videoHeight() const;

    Q_INVOKABLE bool mouseDown(QPoint point);
    Q_INVOKABLE bool mouseMove(QPoint point);
    Q_INVOKABLE bool mouseUp(QPoint point);
    Q_INVOKABLE bool keyEvent(QString key);

public slots:
    void init();
    void start();
    void stop();


private slots:
    void checkForDevice();

signals:
    void videoSurfaceChanged();
    void statusChanged();
    void videoResized();
    void outputResized();
    void playbackStarted();
    void connected(QVariantMap notification);
    void btConnectionRequest(QString address);

private:
    QTimer* m_deviceCheckTimer = nullptr;
    Headunit* m_headunit;
    int m_outputWidth = 1280;
    int m_outputHeight = 720;
};



#endif // AASERVICE_H