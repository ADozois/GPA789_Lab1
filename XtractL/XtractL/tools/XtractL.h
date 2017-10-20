
#ifndef X_TRACT_L_H
#define X_TRACT_L_H

#include <exception>
#include <string>
#include <iostream>
#include <fstream>

#include "AutomatonFileStatExtraction.h"
#include "AutomatonCppLiteralExtraction.h"

class XtractL
{
public:
	XtractL();
	~XtractL();

	//! Texte expiquant le synopsis de la fonction.
	static const std::string CommandLineArgumentUsage;

	//! Initialisation de la classe. Le fichier d'entrée est spécifié 
	//! et la sortie est produite directement sur la console.
	void setup(const std::string & inputFileName);
	//! Initialisation de la classe. Le fichier d'entrée est spécifié 
	//! et la sortie est produite dans le fichier spécifié.
	void setup(const std::string & inputFileName, const std::string & outputFileName);
	//! Initialisation de la classe. Le fichier d'entrée est spécifié 
	//! et la sortie est produite dans le fichier spécifié.
	void setup(const std::string & inputFileName, std::stringstream & outputstring);
	//! Initialisation de la classe en analysant les arguments passés 
	//! par la ligne de commande.
	void setup(int argc, char **argv);

	//! Effectue tout le traitement des automates sur le fichier d'entrée
	//! déjà donné. Il est important d'avoir initialiser la classe avec 
	//! `setup`.
	void process(bool includeStats);

	class Exception;
	class ParamException;

private:
	static const std::string OpenInputFileErrorString;
	static const std::string OpenOutputFileErrorString;
	static const std::string ReadCharacterFromInputFileString;

	std::ifstream mInputFile;
	std::ofstream mOutputFile;
	std::ostream * mOStream;

	void openInputFile(const std::string & inputFileName);
	void openOutputFile(const std::string & outputFileName);
	void writeStats();

	AutomatonFileStatExtraction mFileStatExtraction;
	AutomatonCppLiteralExtraction mCppLiteralExtraction;
	bool mFileStatExctractionAccepted{ false };
	bool mCppLiteralExtractionAccepted{ false };
};

//! \exception XtractL::Exception
//! \brief	Classe utilitaire de XtractL pour la gestion d'exception générale.
class XtractL::Exception
{
public:
	Exception() = default;
	Exception(const std::string & context, const std::string & cause);
	virtual ~Exception() = default;

	void setContext(const std::string& context) { mContext = context; }
	void setCause(const std::string& cause) { mCause = cause; }

	const std::string& context() const { return mContext; }
	const std::string& cause() const { return mCause; }

	std::string what() const;

protected:
	std::string mContext;
	std::string mCause;
};



//! \exception XtractL::ParamException
//! \brief	Classe utilitaire de XtractL pour la gestion d'exception reliée aux paramètres.
class XtractL::ParamException : public XtractL::Exception
{
public:
	ParamException();
	ParamException(const std::string & context);
	~ParamException() = default;

private:
	static const std::string CauseString;
	using Exception::setCause;
};

#endif // !X_TRACT_L_H



