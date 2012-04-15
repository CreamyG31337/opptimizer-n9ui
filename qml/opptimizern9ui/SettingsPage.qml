// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Page{
    anchors.margins: UiConstants.DefaultMargin
    Row {
         id: rowEnabled
         anchors{
             topMargin: 10
             top: parent.top
             right: parent.right
             left: parent.left
         }
         Label {
             width: rowEnabled.width - rowEnabled.spacing - swOCEnabled.width
             height: swOCEnabled.height
             verticalAlignment: Text.AlignVCenter
             text: "Apply on Startup"
         }
         Switch {
             id: swOCEnabled
         }
     }

    Row {
         id: rowSR
         anchors{
             topMargin: 10
             top: rowEnabled.bottom
             right: parent.right
             left: parent.left
         }
         Label {
             width: rowSR.width - rowSR.spacing - swSmartReflex.width
             height: swSmartReflex.height
             text: "SmartReflex"
         }
         Switch {
             id: swSmartReflex
         }
    }

    Label {
        id:lblFreq
        anchors{
            top: rowSR.bottom
            left: parent.left
        }
        text: "Frequency (MHz): "
    }
    CountBubble{
        id: cbFreq
        anchors.left: lblFreq.right
        anchors.verticalCenter: lblFreq.verticalCenter
        value: sliderFreq.value
        largeSized: true
    }

    Slider {
        id: sliderFreq
        anchors{
         top: lblFreq.bottom
         left: parent.left
         right: parent.right
        }
        maximumValue: 1400
             minimumValue: 800
             value: 1000
             stepSize: 5
     }

    Label {
        id: lblOCVolts
        anchors{
            top: sliderFreq.bottom
            left: parent.left
        }
        text: "Voltage (uV): "
    }

    CountBubble{
        id: cbVolts
        anchors.left: lblOCVolts.right
        anchors.verticalCenter: lblOCVolts.verticalCenter
        value: sliderVolts.value
        largeSized: true
    }

    Slider {
        id: sliderVolts
        anchors{
            top: lblOCVolts.bottom
            left: parent.left
            right: parent.right
        }
        minimumValue: 1000000
        maximumValue: 1387500
        value: 1375000
        stepSize: 12500
     }

    Button{
        id: btnApply
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        text: "Apply"
        onClicked: {

        }
    }
}
