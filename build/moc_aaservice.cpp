/****************************************************************************
** Meta object code from reading C++ file 'aaservice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/aaservice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aaservice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AAService_t {
    QByteArrayData data[28];
    char stringdata0[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AAService_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AAService_t qt_meta_stringdata_AAService = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AAService"
QT_MOC_LITERAL(1, 10, 19), // "videoSurfaceChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "statusChanged"
QT_MOC_LITERAL(4, 45, 12), // "videoResized"
QT_MOC_LITERAL(5, 58, 13), // "outputResized"
QT_MOC_LITERAL(6, 72, 15), // "playbackStarted"
QT_MOC_LITERAL(7, 88, 9), // "connected"
QT_MOC_LITERAL(8, 98, 12), // "notification"
QT_MOC_LITERAL(9, 111, 19), // "btConnectionRequest"
QT_MOC_LITERAL(10, 131, 7), // "address"
QT_MOC_LITERAL(11, 139, 4), // "init"
QT_MOC_LITERAL(12, 144, 5), // "start"
QT_MOC_LITERAL(13, 150, 4), // "stop"
QT_MOC_LITERAL(14, 155, 14), // "checkForDevice"
QT_MOC_LITERAL(15, 170, 9), // "mouseDown"
QT_MOC_LITERAL(16, 180, 5), // "point"
QT_MOC_LITERAL(17, 186, 9), // "mouseMove"
QT_MOC_LITERAL(18, 196, 7), // "mouseUp"
QT_MOC_LITERAL(19, 204, 8), // "keyEvent"
QT_MOC_LITERAL(20, 213, 3), // "key"
QT_MOC_LITERAL(21, 217, 12), // "videoSurface"
QT_MOC_LITERAL(22, 230, 22), // "QAbstractVideoSurface*"
QT_MOC_LITERAL(23, 253, 6), // "status"
QT_MOC_LITERAL(24, 260, 10), // "videoWidth"
QT_MOC_LITERAL(25, 271, 11), // "videoHeight"
QT_MOC_LITERAL(26, 283, 11), // "outputWidth"
QT_MOC_LITERAL(27, 295, 12) // "outputHeight"

    },
    "AAService\0videoSurfaceChanged\0\0"
    "statusChanged\0videoResized\0outputResized\0"
    "playbackStarted\0connected\0notification\0"
    "btConnectionRequest\0address\0init\0start\0"
    "stop\0checkForDevice\0mouseDown\0point\0"
    "mouseMove\0mouseUp\0keyEvent\0key\0"
    "videoSurface\0QAbstractVideoSurface*\0"
    "status\0videoWidth\0videoHeight\0outputWidth\0"
    "outputHeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AAService[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       6,  116, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    1,   94,    2, 0x06 /* Public */,
       9,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  100,    2, 0x0a /* Public */,
      12,    0,  101,    2, 0x0a /* Public */,
      13,    0,  102,    2, 0x0a /* Public */,
      14,    0,  103,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      15,    1,  104,    2, 0x02 /* Public */,
      17,    1,  107,    2, 0x02 /* Public */,
      18,    1,  110,    2, 0x02 /* Public */,
      19,    1,  113,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap,    8,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool, QMetaType::QPoint,   16,
    QMetaType::Bool, QMetaType::QPoint,   16,
    QMetaType::Bool, QMetaType::QPoint,   16,
    QMetaType::Bool, QMetaType::QString,   20,

 // properties: name, type, flags
      21, 0x80000000 | 22, 0x0049510b,
      23, QMetaType::Int, 0x00495001,
      24, QMetaType::Int, 0x00495001,
      25, QMetaType::Int, 0x00495001,
      26, QMetaType::Int, 0x00495003,
      27, QMetaType::Int, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       2,
       3,
       3,

       0        // eod
};

void AAService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AAService *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->videoSurfaceChanged(); break;
        case 1: _t->statusChanged(); break;
        case 2: _t->videoResized(); break;
        case 3: _t->outputResized(); break;
        case 4: _t->playbackStarted(); break;
        case 5: _t->connected((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 6: _t->btConnectionRequest((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->init(); break;
        case 8: _t->start(); break;
        case 9: _t->stop(); break;
        case 10: _t->checkForDevice(); break;
        case 11: { bool _r = _t->mouseDown((*reinterpret_cast< QPoint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->mouseMove((*reinterpret_cast< QPoint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->mouseUp((*reinterpret_cast< QPoint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->keyEvent((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AAService::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AAService::videoSurfaceChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AAService::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AAService::statusChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AAService::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AAService::videoResized)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AAService::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AAService::outputResized)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AAService::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AAService::playbackStarted)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AAService::*)(QVariantMap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AAService::connected)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (AAService::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AAService::btConnectionRequest)) {
                *result = 6;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractVideoSurface* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AAService *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QAbstractVideoSurface**>(_v) = _t->videoSurface(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->status(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->videoWidth(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->videoHeight(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->m_outputWidth; break;
        case 5: *reinterpret_cast< int*>(_v) = _t->m_outputHeight; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<AAService *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVideoSurface(*reinterpret_cast< QAbstractVideoSurface**>(_v)); break;
        case 4:
            if (_t->m_outputWidth != *reinterpret_cast< int*>(_v)) {
                _t->m_outputWidth = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->outputResized();
            }
            break;
        case 5:
            if (_t->m_outputHeight != *reinterpret_cast< int*>(_v)) {
                _t->m_outputHeight = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->outputResized();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject AAService::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AAService.data,
    qt_meta_data_AAService,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AAService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AAService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AAService.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AAService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AAService::videoSurfaceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AAService::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AAService::videoResized()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AAService::outputResized()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void AAService::playbackStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void AAService::connected(QVariantMap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AAService::btConnectionRequest(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
