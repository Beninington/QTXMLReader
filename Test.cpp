#include "Test.h"

void test01()
{
    cv::Mat A1 = cv::Mat::ones(2748,3580,CV_8UC3);
    cv::Mat Dst = cv::Mat(A1.size(),A1.type());

}
void test02()
{
    //double dbX[9] = {1,2,3,4,5,6,7,8,9};//这里是列优先...
    cv::Mat A2 = (cv::Mat_<double>(3, 3)<< 1,2,3,4,5,6,7,8,9);
    Eigen::Matrix<double,3,3,1> AA;// = Map<MatrixXd>(dbX,3,3);

    AA << 1, 2, 3,     // 初始化A，元素也可以是矩阵，先按列堆叠，再按行堆叠。
         4, 5, 6,
         7, 8, 9;
    Eigen::MatrixXcd Vect;
    Eigen::Matrix<double,3,3,1> Vect2;

    Eigen::EigenSolver<Eigen::MatrixXd> eig(AA);
    std::cout<<"AA = \n"<<AA<<std::endl;
    std::cout << "The eigenvalues of A are:\n "<< eig.eigenvalues() << std::endl;
    std::cout << "The matrix of eigenvectors, V, is:\n " << eig.eigenvectors() << std::endl;

}
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
