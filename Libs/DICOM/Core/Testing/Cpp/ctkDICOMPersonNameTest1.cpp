
// Qt includes
#include <QApplication>
#include <QDir>
#include <QTimer>

// ctkDICOMCore includes
#include "ctkDICOMPersonName.h"

// STD includes
#include <iostream>


int ctkDICOMPersonNameTest1( int argc, char * argv [] )
{
  QApplication app(argc, argv);

  ctkDICOMPersonName personName("lastName", "firstName", "middleName", "namePrefix", "nameSuffix");
  if (personName.lastName() != "lastName")
    {
    std::cerr << "ctkDICOMPersonName::lastName() failed:"
              << qPrintable(personName.lastName()) << std::endl;
    return EXIT_FAILURE;
    }

  if (personName.firstName() != "firstName")
    {
    std::cerr << "ctkDICOMPersonName::firstName() failed:"
              << qPrintable(personName.firstName()) << std::endl;
    return EXIT_FAILURE;
    }
  
  if (personName.middleName() != "middleName")
    {
    std::cerr << "ctkDICOMPersonName::middleName() failed:"
              << qPrintable(personName.middleName()) << std::endl;
    return EXIT_FAILURE;
    }
  
  if (personName.namePrefix() != "namePrefix")
    {
    std::cerr << "ctkDICOMPersonName::namePrefix() failed:"
              << qPrintable(personName.namePrefix()) << std::endl;
    return EXIT_FAILURE;
    }
    
  if (personName.nameSuffix() != "nameSuffix")
    {
    std::cerr << "ctkDICOMPersonName::nameSuffix() failed:"
              << qPrintable(personName.nameSuffix()) << std::endl;
    return EXIT_FAILURE;
    }

  if (personName.formattedName() != "lastName, firstName middleName, nameSuffix")
    {
    std::cerr << "ctkDICOMPersonName::nameSuffix() failed:"
              << qPrintable(personName.formattedName()) << std::endl;
    return EXIT_FAILURE;
    }

  // test operator QString()
  if (QString(personName) != QString("lastName, firstName middleName, nameSuffix"))
    {
    std::cerr << "ctkDICOMPersonName::nameSuffix() failed:"
              << qPrintable(QString(personName)) << std::endl;
    return EXIT_FAILURE;
    }

  // test toStdString()
  // TODO: make it fail 
  if (personName.toStdString() != std::string("lastName, firstName middleName, nameSuffix"))
    {
    std::cerr << "ctkDICOMPersonName::nameSuffix() failed:"
              << personName.toStdString() << std::endl;
    return EXIT_FAILURE;
    }

  ctkDICOMPersonName samePersonName(personName);
  
  if (samePersonName.lastName() != personName.lastName() ||
      samePersonName.firstName() != personName.firstName() ||
      samePersonName.middleName() != personName.middleName() ||
      samePersonName.namePrefix() != personName.namePrefix() ||
      samePersonName.nameSuffix() != personName.nameSuffix() || 
      samePersonName.formattedName() != personName.formattedName())
    {
    std::cerr << "ctkDICOMPersonName::ctkDICOMPersonName(ctkDICOMPersonName&) failed:"
              << qPrintable(samePersonName.formattedName()) << std::endl;
    return EXIT_FAILURE;
    }
  ctkDICOMPersonName otherPerson("just a last name");
  if (otherPerson.lastName() != "just a last name" ||
      !otherPerson.firstName().isEmpty() ||
      !otherPerson.middleName().isEmpty() ||
      !otherPerson.namePrefix().isEmpty() ||
      !otherPerson.nameSuffix().isEmpty() ||
      otherPerson.formattedName() != "just a last name")
    {
    std::cerr << "ctkDICOMPersonName with empty fields failed:"
              << qPrintable(otherPerson.formattedName()) << std::endl;
    return EXIT_FAILURE;
    }

  otherPerson = samePersonName;
  
  if (otherPerson.lastName() != personName.lastName() ||
      otherPerson.firstName() != personName.firstName() ||
      otherPerson.middleName() != personName.middleName() ||
      otherPerson.namePrefix() != personName.namePrefix() ||
      otherPerson.nameSuffix() != personName.nameSuffix() || 
      otherPerson.formattedName() != personName.formattedName())
    {
    std::cerr << "ctkDICOMPersonName::operator=(const ctkDICOMPersonName&) failed:"
              << qPrintable(otherPerson.formattedName()) << std::endl;
    return EXIT_FAILURE;
    }

  if (argc <= 1 || QString(argv[1]) != "-I")
    {
    QTimer::singleShot(200, &app, SLOT(quit()));
    }

  return app.exec();
}