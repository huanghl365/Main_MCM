/****************************************************************************
** Meta object code from reading C++ file 'logdialog.h'
**
** Created: Fri Dec 7 17:17:24 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "logdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      25,   10,   10,   10, 0x08,
      49,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LogDialog[] = {
    "LogDialog\0\0LoginWindow()\0"
    "on_uartbutton_clicked()\0on_netbutton_clicked()\0"
};

void LogDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LogDialog *_t = static_cast<LogDialog *>(_o);
        switch (_id) {
        case 0: _t->LoginWindow(); break;
        case 1: _t->on_uartbutton_clicked(); break;
        case 2: _t->on_netbutton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LogDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LogDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LogDialog,
      qt_meta_data_LogDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LogDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LogDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LogDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogDialog))
        return static_cast<void*>(const_cast< LogDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int LogDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
