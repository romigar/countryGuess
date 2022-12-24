#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>

bool validDistance(QByteArray reference, QByteArray candidat, double tolerance);
bool validDistance(std::string reference, std::string candidat, double tolerance);

#endif // TOOLS_H
