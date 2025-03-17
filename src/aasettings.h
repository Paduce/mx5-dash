#ifndef AASETTINGS_H
#define AASETTINGS_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <QMap>
#include <QString>
#include <string>
#include <map>

class AASettings : public QObject
{
    Q_OBJECT

public:
    // Singleton pattern
    static AASettings* instance() {
        static AASettings instance;
        return &instance;
    }

    // Initialize settings with defaults
    void initialize() {
        // Check if required settings exist, set defaults if not
        if (!m_settings.contains("dpi")) {
            m_settings.setValue("dpi", "240");
        }
        
        if (!m_settings.contains("resolution")) {
            m_settings.setValue("resolution", "2");
        }
        
        // Add inputmode setting with default of touch
        if (!m_settings.contains("inputmode")) {
            m_settings.setValue("inputmode", "touch");
        }
        
        // Optional: For testing different modes, uncomment one of these:
        // m_settings.setValue("inputmode", "rotary");
        // m_settings.setValue("inputmode", "hybrid");
        
        qDebug() << "AASettings initialized";
    }

    // Get a specific setting with a default fallback
    QString getSetting(const QString& key, const QString& defaultValue = "") {
        return m_settings.value(key, defaultValue).toString();
    }
    
    // Set a specific setting
    void setSetting(const QString& key, const QString& value) {
        m_settings.setValue(key, value);
    }
    
    // Get all settings as a standard map for C++ code
    std::map<std::string, std::string> getStdStringMap() {
        std::map<std::string, std::string> result;
        
        // Get all keys
        QStringList keys = m_settings.allKeys();
        for (const QString& key : keys) {
            QString value = m_settings.value(key).toString();
            result[key.toStdString()] = value.toStdString();
        }
        
        return result;
    }
    
    // Debug function to print all settings
    void dumpConfigInfo() {
        qDebug() << "Android Auto Settings:";
        qDebug() << "  DPI:" << m_settings.value("dpi", "240").toString();
        qDebug() << "  Resolution:" << m_settings.value("resolution", "2").toString();
        qDebug() << "  Input Mode:" << m_settings.value("inputmode", "touch").toString();
        
        // Print all other settings
        QStringList keys = m_settings.allKeys();
        for (const QString& key : keys) {
            if (key != "dpi" && key != "resolution" && key != "inputmode") {
                qDebug() << "  " << key << ":" << m_settings.value(key).toString();
            }
        }
    }

private:
    // Private constructor for singleton
    AASettings(QObject *parent = nullptr) : QObject(parent) {
        // Use INI format for settings
        m_settings.setIniCodec("UTF-8");
    }
    
    // Prevent copying
    AASettings(const AASettings&) = delete;
    AASettings& operator=(const AASettings&) = delete;
    
    // Settings storage
    QSettings m_settings{"android_auto_config.ini", QSettings::IniFormat};
};

#endif // AASETTINGS_H