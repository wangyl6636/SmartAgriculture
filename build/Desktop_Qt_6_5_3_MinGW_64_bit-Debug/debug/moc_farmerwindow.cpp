/****************************************************************************
** Meta object code from reading C++ file 'farmerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../farmerwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'farmerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSFarmerWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFarmerWindowENDCLASS = QtMocHelpers::stringData(
    "FarmerWindow",
    "logout",
    "",
    "refreshSuggestions",
    "UpdateButtonClicked",
    "ReShow",
    "on_suggestButton_clicked",
    "on_viewSystemAdviceButton_clicked",
    "onLogOut"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFarmerWindowENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[13];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[20];
    char stringdata5[7];
    char stringdata6[25];
    char stringdata7[34];
    char stringdata8[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFarmerWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFarmerWindowENDCLASS_t qt_meta_stringdata_CLASSFarmerWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "FarmerWindow"
        QT_MOC_LITERAL(13, 6),  // "logout"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 18),  // "refreshSuggestions"
        QT_MOC_LITERAL(40, 19),  // "UpdateButtonClicked"
        QT_MOC_LITERAL(60, 6),  // "ReShow"
        QT_MOC_LITERAL(67, 24),  // "on_suggestButton_clicked"
        QT_MOC_LITERAL(92, 33),  // "on_viewSystemAdviceButton_cli..."
        QT_MOC_LITERAL(126, 8)   // "onLogOut"
    },
    "FarmerWindow",
    "logout",
    "",
    "refreshSuggestions",
    "UpdateButtonClicked",
    "ReShow",
    "on_suggestButton_clicked",
    "on_viewSystemAdviceButton_clicked",
    "onLogOut"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFarmerWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject FarmerWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSFarmerWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFarmerWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFarmerWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FarmerWindow, std::true_type>,
        // method 'logout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refreshSuggestions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'UpdateButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ReShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_suggestButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_viewSystemAdviceButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLogOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void FarmerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FarmerWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logout(); break;
        case 1: _t->refreshSuggestions(); break;
        case 2: _t->UpdateButtonClicked(); break;
        case 3: _t->ReShow(); break;
        case 4: _t->on_suggestButton_clicked(); break;
        case 5: _t->on_viewSystemAdviceButton_clicked(); break;
        case 6: _t->onLogOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FarmerWindow::*)();
            if (_t _q_method = &FarmerWindow::logout; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *FarmerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FarmerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFarmerWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FarmerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FarmerWindow::logout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
