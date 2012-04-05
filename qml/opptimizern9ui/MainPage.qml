import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    Text {
        id: settingstext

            anchors{
                top:parent.top
                topMargin:10
                right:parent.right
                left:parent.left
            }

            text: "Settings:"
            font.pointSize: 18
        }

    Row {
             id: ocactivaterow
             spacing: 10
             anchors{
                 top:settingstext.bottom
                 topMargin: 5
                 right:parent.right
                 rightMargin: 10
                 left:parent.left
                 leftMargin: 10
             }


             Text {
                 width: ocactivaterow.width - ocactivaterow.spacing - ocactivateswitch.width
                 height: ocactivateswitch.height
                 verticalAlignment: Text.AlignVCenter
                 text: ocactivateswitch.checked ? "Overclocking on" : "Overclocking off"

             }
             Switch {

                 id: ocactivateswitch
             }

         }

    Row {
             id: smartreflex
             spacing: 10
             anchors{
                 top:ocactivaterow.bottom
                 topMargin: 10
                 right:parent.right
                 rightMargin: 10
                 left:parent.left
                 leftMargin: 10
             }


             Text {
                 width: smartreflex.width - smartreflex.spacing - smartreflexswitch.width
                 height: smartreflexswitch.height
                 verticalAlignment: Text.AlignVCenter
                 text: smartreflexswitch.checked ? "SmartReflex on" : "SmartReflex off"

             }
             Switch {


                 id: smartreflexswitch
             }

         }

    Text {
        id:textocfreq
        anchors{
            top:smartreflex.bottom
            topMargin: 20
            right:parent.right
            left:parent.left
        }

        text: "Frequency :"
        font.pointSize: 20
        wrapMode: Text.WrapAnywhere

    }

    Slider {
        id: ocslider
        anchors{
         top:textocfreq.bottom
         topMargin: 30
        }
        maximumValue: 1200
             minimumValue: 300
             value: 1000
             stepSize: 50
             valueIndicatorVisible: true
     }
    ToolBarLayout {
         id: commonTools
         ToolItem  {
             iconId: "icon-m-toolbar-back";
             onClicked: Qt.quit()
         }
         ToolButtonRow {
             ToolButton {
                 id: tabButSave
                 text: "Save"
             }
             ToolButton {
                 id: tabButReset
                 text: "Reset to defaults"
             }

         }
     }

}
