#ifndef AASERVICE_H
#define AASERVICE_H

#include <QObject>
#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>
#include <QTimer>
#include <memory>

// We need to define the InputMode enum here to avoid including headunit.h
// which would create circular dependencies
class Headunit; // Forward declaration still needed

class AAService : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ videoSurface WRITE setVideoSurface NOTIFY videoSurfaceChanged)
    Q_PROPERTY(int status READ status NOTIFY statusChanged)
    Q_PROPERTY(int videoWidth READ videoWidth NOTIFY videoResized)
    Q_PROPERTY(int videoHeight READ videoHeight NOTIFY videoResized)
    Q_PROPERTY(int outputWidth MEMBER m_outputWidth NOTIFY outputResized)
    Q_PROPERTY(int outputHeight MEMBER m_outputHeight NOTIFY outputResized)
    Q_PROPERTY(int inputMode READ inputMode WRITE setInputMode NOTIFY inputModeChanged)

public:
    // Define the InputMode enum here rather than using Headunit's version
    enum InputMode {
        INPUT_MODE_TOUCH = 0,
        INPUT_MODE_ROTARY = 1,
        INPUT_MODE_HYBRID = 2
    };
    Q_ENUM(InputMode)

    explicit AAService(QObject *parent = nullptr);
    virtual ~AAService();

    QAbstractVideoSurface* videoSurface() const;
    void setVideoSurface(QAbstractVideoSurface* surface);

    int status() const;
    int videoWidth() const;
    int videoHeight() const;
    
    // Changed to use our local InputMode enum instead of Headunit's
    int inputMode() const; // Changed return type to int for Q_PROPERTY compatibility
    void setInputMode(int mode); // Changed parameter type to int for Q_PROPERTY compatibility

    Q_INVOKABLE bool mouseDown(QPoint point);
    Q_INVOKABLE bool mouseMove(QPoint point);
    Q_INVOKABLE bool mouseUp(QPoint point);
    Q_INVOKABLE bool keyEvent(QString key);

    // Rotary controller methods
    Q_INVOKABLE bool rotateClockwise();
    Q_INVOKABLE bool rotateCounterClockwise();
    Q_INVOKABLE bool rotateFlickClockwise();
    Q_INVOKABLE bool rotateFlickCounterClockwise();
    Q_INVOKABLE bool dpadClick();
    Q_INVOKABLE bool dpadBack();
    Q_INVOKABLE bool dpadUp();
    Q_INVOKABLE bool dpadDown();
    Q_INVOKABLE bool dpadLeft();
    Q_INVOKABLE bool dpadRight();

public slots:
    void init();
    void start();
    void stop();

private slots:
    void checkForDevice();
    
private:
    void applyCustomSettings();

signals:
    void videoSurfaceChanged();
    void statusChanged();
    void videoResized();
    void outputResized();
    void inputModeChanged();
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