import QtQuick 2.15
import QtQuick.Window 2.15

Window
{
    width: 640
    height: 500
    visible: true
    title: qsTr("the list")
    ListView
    {
        id : myid
        width: 380;
        height: 40 * myid.count
        model: A.reading_()/*["name"]*/
//        orientation: Qt.Horizontal
        delegate:
        Item
        {
            id: id_r
            width: 800
            height: 60
            Text
            {
                id: id_id
//                height: 40
                width: id_id.implicitWidth + 20
                horizontalAlignment: Text.AlignHCenter

                font.pointSize: 14
                text: modelData.id

            }
            Rectangle
            {
                id: id_r1
                width: id_t1.implicitWidth + 40
                height: 40
                anchors.left: id_id.right
                border.color: "black"
                radius: 50

                gradient:
                Gradient
                {
                    GradientStop { position: 0.0; color: "crimson" }
                    GradientStop { position: 0.5; color: "yellow" }
                    GradientStop { position: 1.0; color: "lime" }
                }

                Text
                {
                    id: id_t1
                    anchors.horizontalCenter: id_r1.horizontalCenter
                    color: "navy"
                    font.pointSize: 15
                    font.bold:true
//                    text: ("%2. %1").arg(modelData.name).arg(modelData.id)
                    text: modelData.name

                }

            }
            Rectangle
            {
                id: id_r2
                width: id_t2.implicitWidth + 20
                height: 40
                border.color: "black"
                anchors.left: id_r1.right
                radius: 50
                gradient:
                Gradient
                {
                    GradientStop { position: 1.0; color: "crimson" }
                    GradientStop { position: 0.5; color: "yellow" }
                    GradientStop { position: 0.0; color: "lime" }
                }

                Text
                {
                    id: id_t2
                    anchors.horizontalCenter: id_r2.horizontalCenter
                    color: "blue"
                    font.pointSize: 15
                    text: modelData.surname
                }
            }
        }
    }
}
