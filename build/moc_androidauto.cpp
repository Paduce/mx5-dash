/****************************************************************************
** Meta object code from reading C++ file 'androidauto.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../modules/android-auto/androidauto.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'androidauto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AndroidAutoPlugin_t {
    QByteArrayData data[7];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AndroidAutoPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AndroidAutoPlugin_t qt_meta_stringdata_AndroidAutoPlugin = {
    {
QT_MOC_LITERAL(0, 0, 17), // "AndroidAutoPlugin"
QT_MOC_LITERAL(1, 18, 15), // "playbackStarted"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 7), // "message"
QT_MOC_LITERAL(4, 43, 2), // "id"
QT_MOC_LITERAL(5, 46, 12), // "eventMessage"
QT_MOC_LITERAL(6, 59, 15) // "huStatusChanged"

    },
    "AndroidAutoPlugin\0playbackStarted\0\0"
    "message\0id\0eventMessage\0huStatusChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AndroidAutoPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    2,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   40,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    4,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    4,    3,
    QMetaType::Void,

       0        // eod
};

void AndroidAutoPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AndroidAutoPlugin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->playbackStarted(); break;
        case 1: _t->message((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 2: _t->eventMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 3: _t->huStatusChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AndroidAutoPlugin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AndroidAutoPlugin::playbackStarted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AndroidAutoPlugin::*)(QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AndroidAutoPlugin::message)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AndroidAutoPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AndroidAutoPlugin.data,
    qt_meta_data_AndroidAutoPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AndroidAutoPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AndroidAutoPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AndroidAutoPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "PluginInterface"))
        return static_cast< PluginInterface*>(this);
    if (!strcmp(_clname, "MediaInterface"))
        return static_cast< MediaInterface*>(this);
    if (!strcmp(_clname, "org.viktorgino.Headunit.PluginInterface"))
        return static_cast< PluginInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int AndroidAutoPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AndroidAutoPlugin::playbackStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AndroidAutoPlugin::message(QString _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x23,  'o',  'r',  'g',  '.',  'v', 
    'i',  'k',  't',  'o',  'r',  'g',  'i',  'n', 
    'o',  '.',  'h',  'e',  'a',  'd',  'u',  'n', 
    'i',  't',  '.',  'a',  'n',  'd',  'r',  'o', 
    'i',  'd',  'a',  'u',  't',  'o', 
    // "className"
    0x03,  0x71,  'A',  'n',  'd',  'r',  'o',  'i', 
    'd',  'A',  'u',  't',  'o',  'P',  'l',  'u', 
    'g',  'i',  'n', 
    // "MetaData"
    0x04,  0xa5,  0x66,  'c',  'o',  'n',  'f',  'i', 
    'g',  0xa3,  0x65,  'i',  't',  'e',  'm',  's', 
    0x89,  0xa6,  0x6c,  'd',  'e',  'f',  'a',  'u', 
    'l',  't',  'V',  'a',  'l',  'u',  'e',  0xf4, 
    0x65,  'l',  'a',  'b',  'e',  'l',  0x78,  0x1b, 
    'P',  'l',  'a',  'y',  ' ',  'N',  'a',  't', 
    'i',  'v',  'e',  ' ',  'M',  'e',  'd',  'i', 
    'a',  ' ',  'd',  'u',  'r',  'i',  'n',  'g', 
    ' ',  'V',  'R',  0x64,  'n',  'a',  'm',  'e', 
    0x78,  0x1f,  'c',  'a',  'n',  '_',  'p',  'l', 
    'a',  'y',  '_',  'n',  'a',  't',  'i',  'v', 
    'e',  '_',  'm',  'e',  'd',  'i',  'a',  '_', 
    'd',  'u',  'r',  'i',  'n',  'g',  '_',  'v', 
    'r',  0x67,  't',  'e',  'x',  't',  'O',  'f', 
    'f',  0x63,  'O',  'f',  'f',  0x66,  't',  'e', 
    'x',  't',  'O',  'n',  0x62,  'O',  'n',  0x64, 
    't',  'y',  'p',  'e',  0x66,  's',  'w',  'i', 
    't',  'c',  'h',  0xa6,  0x6c,  'd',  'e',  'f', 
    'a',  'u',  'l',  't',  'V',  'a',  'l',  'u', 
    'e',  0xf4,  0x65,  'l',  'a',  'b',  'e',  'l', 
    0x6a,  'H',  'i',  'd',  'e',  ' ',  'c',  'l', 
    'o',  'c',  'k',  0x64,  'n',  'a',  'm',  'e', 
    0x6a,  'h',  'i',  'd',  'e',  '_',  'c',  'l', 
    'o',  'c',  'k',  0x67,  't',  'e',  'x',  't', 
    'O',  'f',  'f',  0x63,  'O',  'f',  'f',  0x66, 
    't',  'e',  'x',  't',  'O',  'n',  0x62,  'O', 
    'n',  0x64,  't',  'y',  'p',  'e',  0x66,  's', 
    'w',  'i',  't',  'c',  'h',  0xa6,  0x6c,  'd', 
    'e',  'f',  'a',  'u',  'l',  't',  'V',  'a', 
    'l',  'u',  'e',  0xf4,  0x65,  'l',  'a',  'b', 
    'e',  'l',  0x71,  'A',  'v',  'a',  'i',  'l', 
    'a',  'b',  'l',  'e',  ' ',  'i',  'n',  ' ', 
    'c',  'a',  'l',  'l',  0x64,  'n',  'a',  'm', 
    'e',  0x77,  'a',  'v',  'a',  'i',  'l',  'a', 
    'b',  'l',  'e',  '_',  'w',  'h',  'i',  'l', 
    'e',  '_',  'i',  'n',  '_',  'c',  'a',  'l', 
    'l',  0x67,  't',  'e',  'x',  't',  'O',  'f', 
    'f',  0x63,  'O',  'f',  'f',  0x66,  't',  'e', 
    'x',  't',  'O',  'n',  0x62,  'O',  'n',  0x64, 
    't',  'y',  'p',  'e',  0x66,  's',  'w',  'i', 
    't',  'c',  'h',  0xa6,  0x6c,  'd',  'e',  'f', 
    'a',  'u',  'l',  't',  'V',  'a',  'l',  'u', 
    'e',  0x19,  0x01,  0x2c,  0x65,  'l',  'a',  'b', 
    'e',  'l',  0x6d,  'P',  'i',  'x',  'e',  'l', 
    ' ',  'd',  'e',  'n',  's',  'i',  't',  'y', 
    0x64,  'n',  'a',  'm',  'e',  0x63,  'd',  'p', 
    'i',  0x66,  's',  'u',  'f',  'f',  'i',  'x', 
    0x63,  'D',  'P',  'I',  0x68,  't',  'e',  'x', 
    't',  'T',  'y',  'p',  'e',  0x63,  'i',  'n', 
    't',  0x64,  't',  'y',  'p',  'e',  0x69,  't', 
    'e',  'x',  't',  'f',  'i',  'e',  'l',  'd', 
    0xa5,  0x6c,  'd',  'e',  'f',  'a',  'u',  'l', 
    't',  'V',  'a',  'l',  'u',  'e',  0x61,  '2', 
    0x65,  'l',  'a',  'b',  'e',  'l',  0x6a,  'R', 
    'e',  's',  'o',  'l',  'u',  't',  'i',  'o', 
    'n',  0x64,  'n',  'a',  'm',  'e',  0x6a,  'r', 
    'e',  's',  'o',  'l',  'u',  't',  'i',  'o', 
    'n',  0x64,  't',  'y',  'p',  'e',  0x68,  'c', 
    'o',  'm',  'b',  'o',  'b',  'o',  'x',  0x66, 
    'v',  'a',  'l',  'u',  'e',  's',  0xa3,  0x61, 
    '1',  0x67,  '8',  '0',  '0',  'x',  '4',  '8', 
    '0',  0x61,  '2',  0x68,  '1',  '2',  '8',  '0', 
    'x',  '7',  '2',  '0',  0x61,  '3',  0x69,  '1', 
    '9',  '2',  '0',  'x',  '1',  '0',  '8',  '0', 
    0xa5,  0x6c,  'd',  'e',  'f',  'a',  'u',  'l', 
    't',  'V',  'a',  'l',  'u',  'e',  0x61,  '2', 
    0x65,  'l',  'a',  'b',  'e',  'l',  0x6a,  'F', 
    'r',  'a',  'm',  'e',  ' ',  'r',  'a',  't', 
    'e',  0x64,  'n',  'a',  'm',  'e',  0x6a,  'f', 
    'r',  'a',  'm',  'e',  '_',  'r',  'a',  't', 
    'e',  0x64,  't',  'y',  'p',  'e',  0x68,  'c', 
    'o',  'm',  'b',  'o',  'b',  'o',  'x',  0x66, 
    'v',  'a',  'l',  'u',  'e',  's',  0xa2,  0x61, 
    '1',  0x66,  '3',  '0',  ' ',  'F',  'P',  'S', 
    0x61,  '2',  0x66,  '6',  '0',  ' ',  'F',  'P', 
    'S',  0xa5,  0x6c,  'd',  'e',  'f',  'a',  'u', 
    'l',  't',  'V',  'a',  'l',  'u',  'e',  0x63, 
    'u',  's',  'b',  0x65,  'l',  'a',  'b',  'e', 
    'l',  0x6e,  'T',  'r',  'a',  'n',  's',  'p', 
    'o',  'r',  't',  ' ',  't',  'y',  'p',  'e', 
    0x64,  'n',  'a',  'm',  'e',  0x6e,  't',  'r', 
    'a',  'n',  's',  'p',  'o',  'r',  't',  '_', 
    't',  'y',  'p',  'e',  0x64,  't',  'y',  'p', 
    'e',  0x68,  'c',  'o',  'm',  'b',  'o',  'b', 
    'o',  'x',  0x66,  'v',  'a',  'l',  'u',  'e', 
    's',  0xa2,  0x67,  'n',  'e',  't',  'w',  'o', 
    'r',  'k',  0x67,  'N',  'e',  't',  'w',  'o', 
    'r',  'k',  0x63,  'u',  's',  'b',  0x63,  'U', 
    'S',  'B',  0xa9,  0x6f,  'c',  'o',  'n',  'd', 
    'i',  't',  'i',  'o',  'n',  'T',  'a',  'r', 
    'g',  'e',  't',  0x6e,  't',  'r',  'a',  'n', 
    's',  'p',  'o',  'r',  't',  '_',  't',  'y', 
    'p',  'e',  0x6e,  'c',  'o',  'n',  'd',  'i', 
    't',  'i',  'o',  'n',  'V',  'a',  'l',  'u', 
    'e',  0x67,  'n',  'e',  't',  'w',  'o',  'r', 
    'k',  0x6b,  'c',  'o',  'n',  'd',  'i',  't', 
    'i',  'o',  'n',  'a',  'l',  0xf5,  0x6c,  'd', 
    'e',  'f',  'a',  'u',  'l',  't',  'V',  'a', 
    'l',  'u',  'e',  0x69,  '1',  '2',  '7',  '.', 
    '0',  '.',  '0',  '.',  '1',  0x69,  'i',  'n', 
    'p',  'u',  't',  'M',  'a',  's',  'k',  0x71, 
    '0',  '0',  '0',  '.',  '0',  '0',  '0',  '.', 
    '0',  '0',  '0',  '.',  '0',  '0',  '0',  ';', 
    '_',  0x65,  'l',  'a',  'b',  'e',  'l',  0x6f, 
    'N',  'e',  't',  'w',  'o',  'r',  'k',  ' ', 
    'a',  'd',  'd',  'r',  'e',  's',  's',  0x64, 
    'n',  'a',  'm',  'e',  0x6f,  'n',  'e',  't', 
    'w',  'o',  'r',  'k',  '_',  'a',  'd',  'd', 
    'r',  'e',  's',  's',  0x68,  't',  'e',  'x', 
    't',  'T',  'y',  'p',  'e',  0x66,  's',  't', 
    'r',  'i',  'n',  'g',  0x64,  't',  'y',  'p', 
    'e',  0x69,  't',  'e',  'x',  't',  'f',  'i', 
    'e',  'l',  'd',  0xa9,  0x6f,  'c',  'o',  'n', 
    'd',  'i',  't',  'i',  'o',  'n',  'T',  'a', 
    'r',  'g',  'e',  't',  0x6e,  't',  'r',  'a', 
    'n',  's',  'p',  'o',  'r',  't',  '_',  't', 
    'y',  'p',  'e',  0x6e,  'c',  'o',  'n',  'd', 
    'i',  't',  'i',  'o',  'n',  'V',  'a',  'l', 
    'u',  'e',  0x67,  'n',  'e',  't',  'w',  'o', 
    'r',  'k',  0x6b,  'c',  'o',  'n',  'd',  'i', 
    't',  'i',  'o',  'n',  'a',  'l',  0xf5,  0x6c, 
    'd',  'e',  'f',  'a',  'u',  'l',  't',  'V', 
    'a',  'l',  'u',  'e',  0xf4,  0x65,  'l',  'a', 
    'b',  'e',  'l',  0x6b,  'W',  'i',  'F',  'i', 
    ' ',  'd',  'i',  'r',  'e',  'c',  't',  0x64, 
    'n',  'a',  'm',  'e',  0x6b,  'w',  'i',  'f', 
    'i',  '_',  'd',  'i',  'r',  'e',  'c',  't', 
    0x67,  't',  'e',  'x',  't',  'O',  'f',  'f', 
    0x63,  'O',  'f',  'f',  0x66,  't',  'e',  'x', 
    't',  'O',  'n',  0x62,  'O',  'n',  0x64,  't', 
    'y',  'p',  'e',  0x66,  's',  'w',  'i',  't', 
    'c',  'h',  0x67,  's',  'e',  'c',  't',  'i', 
    'o',  'n',  0x6a,  'M',  'e',  'd',  'i',  'a', 
    ' ',  'a',  'p',  'p',  's',  0x64,  't',  'y', 
    'p',  'e',  0x65,  'i',  't',  'e',  'm',  's', 
    0x64,  'i',  'c',  'o',  'n',  0x78,  0x23,  'q', 
    'r',  'c',  ':',  '/',  'A',  'n',  'd',  'r', 
    'o',  'i',  'd',  'A',  'u',  't',  'o',  '/', 
    's',  'o',  'c',  'i',  'a',  'l',  '-',  'a', 
    'n',  'd',  'r',  'o',  'i',  'd',  '.',  's', 
    'v',  'g',  0x65,  'l',  'a',  'b',  'e',  'l', 
    0x6c,  'A',  'n',  'd',  'r',  'o',  'i',  'd', 
    ' ',  'A',  'u',  't',  'o',  0x64,  'n',  'a', 
    'm',  'e',  0x6b,  'A',  'n',  'd',  'r',  'o', 
    'i',  'd',  'A',  'u',  't',  'o',  0x66,  's', 
    'o',  'u',  'r',  'c',  'e',  0x78,  0x1d,  'q', 
    'r',  'c',  ':',  '/',  'A',  'n',  'd',  'r', 
    'o',  'i',  'd',  'A',  'u',  't',  'o',  '/', 
    'n',  'a',  't',  'i',  'v',  'e',  'A',  'A', 
    '.',  'q',  'm',  'l', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(AndroidAutoPlugin, AndroidAutoPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
