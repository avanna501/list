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
        Rectangle
        {
//            id: id_r
//            width: id_r.length()
            width: id_t.implicitWidth + 20/**id_t.length()*/
            height: 40
            color: "cyan"
            border.color: "black"
            gradient: Gradient {
                GradientStop { position: 0.0; color: "crimson" }
                 GradientStop { position: 0.5; color: "yellow" }
                  GradientStop { position: 1.0; color: "lime" }
            }
            radius: 50


            Text
            {
                id: id_t
                color: "navy"
//                font.family: "Futura"
//                font.bold: true
                font.pointSize: 15
                text: ("%1 : %2").arg(modelData.name).arg(modelData.id)
            }
        }
//        Text
//        {
//            text: modelData
//        }
    }
}
