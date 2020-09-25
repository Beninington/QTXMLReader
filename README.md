//# QTXMLReader
//QT XML Read and write
bool readXml(const QString filename)
{
    QMap<QString, std::vector<int>> m_termMap;m_termMap.clear();
    QFile files(filename);
    if(files.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //构建QXmlStreamReader对象
        QXmlStreamReader reader(&files);
        while(!reader.atEnd())
        {
            //判断是否是节点的开始
            if(reader.isStartElement())
            {
                //将属性读出:例如 id="3" age = "23">
                QXmlStreamAttributes attributes = reader.attributes();
                //判断是否存在属性"id"
                if(attributes.hasAttribute("id"))
                {
                    //将属性id追加textBrower
                    qDebug()<< QString("id:%1").arg(attributes.value("id").toString());
                }
                //判断当前节点的名字是否为Number
                if(reader.name() == "Number")
                    qDebug()<< QString("Number:%1").arg(reader.readElementText());
                //判断当前节点的名字是否为Name
                else if(reader.name() == "Name")
                    qDebug()<< QString("Name:%1").arg(reader.readElementText());
                //判断当前节点的名字是否为email
                else if(reader.name() == "email")
                    qDebug()<< QString("email:%1").arg(reader.readElementText());
                //判断当前节点的名字是否为website
                else if(reader.name() == "website")
                    qDebug()<< QString("website:%1").arg(reader.readElementText());
            }
            //节点结束、并且节点名字为Data（含有子节点）
            else if(reader.isEndElement() && reader.name() == "Data")
            {
                qDebug()<< "--------------------";
                qDebug()<< " ";
            }
            reader.readNext();
        }
        files.close();
    }
    else
    {
        qDebug()<<"Open filess XML failure";
        return false;
    }
    return true;
}
