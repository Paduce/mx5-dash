#include "aaservice.h"
#include "headunit.h"

AAService::AAService(QObject *parent) : QObject(parent)
{
    m_headunit = new Headunit(this);

    connect(m_headunit, &Headunit::statusChanged, this, &AAService::statusChanged);
    connect(m_headunit, &Headunit::videoResized, this, &AAService::videoResized);
    connect(m_headunit, &Headunit::playbackStarted, this, &AAService::playbackStarted);
    connect(m_headunit, &Headunit::btConnectionRequest, this, &AAService::btConnectionRequest);
    
    // Create a timer to periodically check for devices
    m_deviceCheckTimer = new QTimer(this);
    connect(m_deviceCheckTimer, &QTimer::timeout, this, &AAService::checkForDevice);
    m_deviceCheckTimer->start(1000); // Check every 2 seconds
}

void AAService::checkForDevice()
{
    // Only attempt reconnection if we're not already connected
    if (m_headunit->status() == Headunit::NO_CONNECTION) {
        qDebug() << "Checking for Android Auto devices...";
        start(); // Attempt to start connection
    }
}

AAService::~AAService()
{
    // The m_headunit pointer will be deleted by Qt's parent-child mechanism
}

QAbstractVideoSurface* AAService::videoSurface() const
{
    return m_headunit->videoSurface();
}

void AAService::setVideoSurface(QAbstractVideoSurface* surface)
{
    qDebug() << "Setting video surface in AAService:" << surface;
    if (m_headunit->videoSurface() != surface) {
        m_headunit->setVideoSurface(surface);
        emit videoSurfaceChanged();
    }
}

int AAService::status() const
{
    return m_headunit->status();
}

int AAService::videoWidth() const
{
    return m_headunit->videoWidth();
}

int AAService::videoHeight() const
{
    return m_headunit->videoHeight();
}

bool AAService::mouseDown(QPoint point)
{
    return m_headunit->mouseDown(point);
}

bool AAService::mouseMove(QPoint point)
{
    return m_headunit->mouseMove(point);
}

bool AAService::mouseUp(QPoint point)
{
    return m_headunit->mouseUp(point);
}

bool AAService::keyEvent(QString key)
{
    return m_headunit->keyEvent(key);
}

void AAService::init()
{
    m_headunit->init();
}

void AAService::start()
{
    if (m_headunit->status() == Headunit::RUNNING) {
        qDebug() << "Android Auto is already running";
        return;
    }
    
    qDebug() << "Attempting to start Android Auto";
    // First ensure initialization is done
    init();
    
    // Try to start the connection
    int result = m_headunit->startHU();
    if (result < 0) {
        qDebug() << "Failed to start Android Auto connection. Will retry automatically.";
    } else {
        qDebug() << "Android Auto connection initiated successfully";
    }
}

void AAService::stop()
{
    m_headunit->stopPipelines();
}