/****************************************************************************
** Meta object code from reading C++ file 'serialTrans.h'
**
** Created: Tue Dec 30 23:26:05 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "serialTrans.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialTrans.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SerialTrans[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,   12,   12,   12, 0x0a,
      42,   12,   12,   12, 0x0a,
      53,   12,   12,   12, 0x0a,
      64,   12,   12,   12, 0x0a,
      77,   12,   12,   12, 0x0a,
      89,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SerialTrans[] = {
    "SerialTrans\0\0serialClosed()\0closeSerial()\0"
    "readData()\0sendData()\0updateData()\0"
    "clearData()\0startAutoSend()\0"
};

const QMetaObject SerialTrans::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SerialTrans,
      qt_meta_data_SerialTrans, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SerialTrans::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SerialTrans::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SerialTrans::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SerialTrans))
        return static_cast<void*>(const_cast< SerialTrans*>(this));
    return QWidget::qt_metacast(_clname);
}

int SerialTrans::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: serialClosed(); break;
        case 1: closeSerial(); break;
        case 2: readData(); break;
        case 3: sendData(); break;
        case 4: updateData(); break;
        case 5: clearData(); break;
        case 6: startAutoSend(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SerialTrans::serialClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
