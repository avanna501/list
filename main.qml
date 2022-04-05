import QtQuick 2.15
import QtQuick.Window 2.15

Window
{
    width: 640
    height: 140
    visible: true
    title: qsTr("the list")
    ListView
    {
        id : myid
        width: 180;
        height: 40 * myid.count
        model: A.reading_()
        delegate:
        Rectangle
        {
            width: 30
            height: 40
            Text
            {
                text: modelData
            }
        }
//        Text
//        {
//            text: modelData
//        }
    }
}
