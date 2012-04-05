import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    tools: commonTools
    id : mainpage

    Row {
             id: ocactivaterow
             spacing: 10
             anchors{
                 top:mainpage.top
                 topMargin: 50
                 right:parent.right
                 left:parent.left
             }

             Switch {
                 id: ocactivateswitch
             }

             Text {
                 width: ocactivaterow.width - ocactivaterow.spacing - ocactivateswitch.width
                 height: ocactivateswitch.height
                 verticalAlignment: Text.AlignVCenter
                 text: ocactivateswitch.checked ? "Overclocking on" : "Overclocking off"
                 font.pixelSize: platformStyle.fontSizeMedium
                 color: platformStyle.colorNormalLight
             }
         }

    Row {
             id: smartreflex
             spacing: 10
             anchors{
                 top:ocactivaterow.bottom
                 topMargin: 5
                 right:parent.right
                 left:parent.left
             }

             Switch {
                 id: smartreflexswitch
             }

             Text {
                 width: smartreflex.width - smartreflex.spacing - smartreflexswitch.width
                 height: smartreflexswitch.height
                 verticalAlignment: Text.AlignVCenter
                 text: smartreflexswitch.checked ? "Switched on" : "Switched off"
                 font.pixelSize: platformStyle.fontSizeMedium
                 color: platformStyle.colorNormalLight
             }
         }

    Text {
        anchors{
            top:smartreflex.bottom
            topMargin: 5
            right:parent.right
            left:parent.left
        }
        verticalAlignment: Text.AlignVCenter
        text: "Choose your oc by using the slider below and click on Set button"
        font.pixelSize: platformStyle.fontSizeMedium
        color: platformStyle.colorNormalLight
    }

    Slider {
        id: ocslider
         maximumValue: 300
         minimumValue: 1200
         value: 1000
         stepSize: 50
         valueIndicatorVisible: true
     }

}
