#ifndef CONSTANTSMODEL_H_
#define CONSTANTSMODEL_H_

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>

class ConstantsModelPoint : public QVariant
{
public:
	ConstantsModelPoint();
	~ConstantsModelPoint();
		
	QString VariableName;
	double Value;
};

class ConstantsModel : public QAbstractTableModel
{
public:
	ConstantsModel();
	virtual ~ConstantsModel();
	
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
	
	Qt::ItemFlags flags(const QModelIndex &index) const;
	
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());	
	
	const QList<ConstantsModelPoint> * getConstantValues() const;
	
private:
	//The actual container for the data
	QList<ConstantsModelPoint> *ConstantValues;
};

#endif /*CONSTANTSMODEL_H_*/
