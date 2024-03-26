/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[41];
    char stringdata0[713];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "getMousePoint"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "lng"
QT_MOC_LITERAL(4, 30, 3), // "lat"
QT_MOC_LITERAL(5, 34, 8), // "getBalls"
QT_MOC_LITERAL(6, 43, 6), // "ballId"
QT_MOC_LITERAL(7, 50, 7), // "ballLng"
QT_MOC_LITERAL(8, 58, 7), // "ballLat"
QT_MOC_LITERAL(9, 66, 9), // "ballColor"
QT_MOC_LITERAL(10, 76, 10), // "whetherOut"
QT_MOC_LITERAL(11, 87, 3), // "msg"
QT_MOC_LITERAL(12, 91, 10), // "getCsvName"
QT_MOC_LITERAL(13, 102, 1), // "Y"
QT_MOC_LITERAL(14, 104, 1), // "M"
QT_MOC_LITERAL(15, 106, 1), // "D"
QT_MOC_LITERAL(16, 108, 1), // "h"
QT_MOC_LITERAL(17, 110, 1), // "m"
QT_MOC_LITERAL(18, 112, 1), // "s"
QT_MOC_LITERAL(19, 114, 11), // "readTcpData"
QT_MOC_LITERAL(20, 126, 12), // "showTcpError"
QT_MOC_LITERAL(21, 139, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(22, 168, 11), // "socketError"
QT_MOC_LITERAL(23, 180, 29), // "on_pushButton_addBall_clicked"
QT_MOC_LITERAL(24, 210, 29), // "on_pushButton_connect_clicked"
QT_MOC_LITERAL(25, 240, 33), // "on_pushButton_sendCommond_cli..."
QT_MOC_LITERAL(26, 274, 30), // "on_pushButton_clearMap_clicked"
QT_MOC_LITERAL(27, 305, 34), // "on_pushButton_showoverlays_cl..."
QT_MOC_LITERAL(28, 340, 26), // "on_pushButton_test_clicked"
QT_MOC_LITERAL(29, 367, 29), // "on_actionReload_Map_triggered"
QT_MOC_LITERAL(30, 397, 24), // "on_actionRuler_triggered"
QT_MOC_LITERAL(31, 422, 35), // "on_pushButton_simulatorInit_c..."
QT_MOC_LITERAL(32, 458, 29), // "on_pushButton_setHome_clicked"
QT_MOC_LITERAL(33, 488, 36), // "on_pushButton_simulatorStart_..."
QT_MOC_LITERAL(34, 525, 28), // "on_pushButton_setEnd_clicked"
QT_MOC_LITERAL(35, 554, 35), // "on_pushButton_serial_search_c..."
QT_MOC_LITERAL(36, 590, 33), // "on_pushButton_serial_open_cli..."
QT_MOC_LITERAL(37, 624, 31), // "on_pushButton_trackBack_clicked"
QT_MOC_LITERAL(38, 656, 11), // "slotTimeout"
QT_MOC_LITERAL(39, 668, 32), // "on_pushButton_getCsvFile_clicked"
QT_MOC_LITERAL(40, 701, 11) // "transStatus"

    },
    "MainWindow\0getMousePoint\0\0lng\0lat\0"
    "getBalls\0ballId\0ballLng\0ballLat\0"
    "ballColor\0whetherOut\0msg\0getCsvName\0"
    "Y\0M\0D\0h\0m\0s\0readTcpData\0showTcpError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "on_pushButton_addBall_clicked\0"
    "on_pushButton_connect_clicked\0"
    "on_pushButton_sendCommond_clicked\0"
    "on_pushButton_clearMap_clicked\0"
    "on_pushButton_showoverlays_clicked\0"
    "on_pushButton_test_clicked\0"
    "on_actionReload_Map_triggered\0"
    "on_actionRuler_triggered\0"
    "on_pushButton_simulatorInit_clicked\0"
    "on_pushButton_setHome_clicked\0"
    "on_pushButton_simulatorStart_clicked\0"
    "on_pushButton_setEnd_clicked\0"
    "on_pushButton_serial_search_clicked\0"
    "on_pushButton_serial_open_clicked\0"
    "on_pushButton_trackBack_clicked\0"
    "slotTimeout\0on_pushButton_getCsvFile_clicked\0"
    "transStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       1,  180, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,  129,    2, 0x0a /* Public */,
       5,    4,  134,    2, 0x0a /* Public */,
      10,    1,  143,    2, 0x0a /* Public */,
      12,    6,  146,    2, 0x0a /* Public */,
      19,    0,  159,    2, 0x08 /* Private */,
      20,    1,  160,    2, 0x08 /* Private */,
      23,    0,  163,    2, 0x08 /* Private */,
      24,    0,  164,    2, 0x08 /* Private */,
      25,    0,  165,    2, 0x08 /* Private */,
      26,    0,  166,    2, 0x08 /* Private */,
      27,    0,  167,    2, 0x08 /* Private */,
      28,    0,  168,    2, 0x08 /* Private */,
      29,    0,  169,    2, 0x08 /* Private */,
      30,    0,  170,    2, 0x08 /* Private */,
      31,    0,  171,    2, 0x08 /* Private */,
      32,    0,  172,    2, 0x08 /* Private */,
      33,    0,  173,    2, 0x08 /* Private */,
      34,    0,  174,    2, 0x08 /* Private */,
      35,    0,  175,    2, 0x08 /* Private */,
      36,    0,  176,    2, 0x08 /* Private */,
      37,    0,  177,    2, 0x08 /* Private */,
      38,    0,  178,    2, 0x08 /* Private */,
      39,    0,  179,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Int,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   14,   15,   16,   17,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      40, QMetaType::QString, 0x00095003,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getMousePoint((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->getBalls((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->whetherOut((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->getCsvName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 4: _t->readTcpData(); break;
        case 5: _t->showTcpError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_addBall_clicked(); break;
        case 7: _t->on_pushButton_connect_clicked(); break;
        case 8: _t->on_pushButton_sendCommond_clicked(); break;
        case 9: _t->on_pushButton_clearMap_clicked(); break;
        case 10: _t->on_pushButton_showoverlays_clicked(); break;
        case 11: _t->on_pushButton_test_clicked(); break;
        case 12: _t->on_actionReload_Map_triggered(); break;
        case 13: _t->on_actionRuler_triggered(); break;
        case 14: _t->on_pushButton_simulatorInit_clicked(); break;
        case 15: _t->on_pushButton_setHome_clicked(); break;
        case 16: _t->on_pushButton_simulatorStart_clicked(); break;
        case 17: _t->on_pushButton_setEnd_clicked(); break;
        case 18: _t->on_pushButton_serial_search_clicked(); break;
        case 19: _t->on_pushButton_serial_open_clicked(); break;
        case 20: _t->on_pushButton_trackBack_clicked(); break;
        case 21: _t->slotTimeout(); break;
        case 22: _t->on_pushButton_getCsvFile_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->isOut; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->isOut != *reinterpret_cast< QString*>(_v)) {
                _t->isOut = *reinterpret_cast< QString*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
