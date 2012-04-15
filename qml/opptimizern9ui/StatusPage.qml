// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Page {
    anchors.margins: UiConstants.DefaultMargin

    BusyIndicator{
        id: myBusyInd
        platformStyle: BusyIndicatorStyle { size: "large" }
        anchors.centerIn: aboutPage
        visible: false
        running: false
        z: 50
    }

    Label{
        id: lblFreqText
        anchors.top: parent.top
        anchors.left: parent.left
        text: "Current Frequency: "
    }

    Label{
        id: lblFreqVal
        anchors.top: parent.top
        anchors.left: lblFreqText.right
        text: "Unknown"
    }

    Label{
        id: lblVoltText
        anchors.left: parent.left
        anchors.top: lblFreqText.bottom
        text: "Current Voltage: "
    }

    Label{
        id: lblVoltVal
        anchors.top: lblFreqText.bottom
        anchors.left: lblVoltText.right
        text: "Unknown"
    }

    Label{
        id: lblModuleText
        anchors.left: parent.left
        anchors.top: lblVoltText.bottom
        text: "Kernel Module Version: "
    }

    Label{
        id: lblModuleVal
        anchors.top: lblVoltText.bottom
        anchors.left: lblModuleText.right
        text: "Unknown"
    }
}
