/****************************************************************************
** Meta object code from reading C++ file 'serialWidget.h'
**
** Created: Tue Dec 30 23:26:06 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "serialWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SerialWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x0a,
      42,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SerialWidget[] = {
    "SerialWidget\0\0data\0startTrans(SerialData)\0"
    "endTrans()\0"
};

const QMetaObject SerialWidget::staticMetaObject = {
    { &QStackedWidget::staticMetaObject, qt_meta_stringdata_SerialWidget,
      qt_meta_data_SerialWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SerialWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SerialWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SerialWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SerialWidget))
        return static_cast<void*>(const_cast< SerialWidget*>(this));
    return QStackedWidget::qt_metacast(_clname);
}

int SerialWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startTrans((*reinterpret_cast< SerialData(*)>(_a[1]))); break;
        case 1: endTrans(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
