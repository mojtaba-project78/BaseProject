import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

//import "./QML/Components"
import "./QML/Windows"
//import "./QML/Forms"
//import "./QML/Pages"

Page {
    visible: true

    WN_Loading {
        id: id_wn_loading
        visible: false
    }
    WN_Startup {
        id: id_wn_startup
        visible: false
    }
    WN_App {
        id: id_wn_app
        visible: false
    }

    function showWindow(index)
    {
        switch(index)
        {
        case 0:
            id_wn_loading.show()
            id_wn_startup.hide()
            id_wn_app.hide()
            break;

        case 1:
            id_wn_loading.hide()
            id_wn_startup.show()
            id_wn_app.hide()
            break;

        case 2:
            id_wn_loading.hide()
            id_wn_startup.hide()
            id_wn_app.show()
            break;
        }
    }
}
