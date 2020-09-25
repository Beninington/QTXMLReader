#ifndef TEST_H
#define TEST_H
#include <QDir>
#include <QFile>
#include <QString>
#include <QDebug>
#include "opencv2/opencv.hpp"
#include <Eigen/Eigen>
#include <QtCore>
#include <QXmlStreamReader>

extern void test01();
extern void test02();
extern bool readXml(const QString fileName);
#endif // TEST_H
