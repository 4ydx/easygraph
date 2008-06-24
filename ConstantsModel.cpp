#include "ConstantsModel.h"

#include <QList>
#include <iostream>

ConstantsModelPoint::ConstantsModelPoint()
{
	X = "";
	Y = 0; 
}

ConstantsModelPoint::~ConstantsModelPoint()
{}

ConstantsModel::ConstantsModel()
{
	ConstantValues = new QList<ConstantsModelPoint>();
}

ConstantsModel::~ConstantsModel()
{
	delete ConstantValues;
}

int ConstantsModel::columnCount(const QModelIndex &parent) const
{
	return 2;	
}

int ConstantsModel::rowCount(const QModelIndex &parent)const
{
	return ConstantValues->size();	
}

QVariant ConstantsModel::data(const QModelIndex &index, int role) const
{
	if(index.column() == 0)
		return QVariant(ConstantValues->at(index.row()).X);
	
	if(index.column() == 1)
		return QVariant(ConstantValues->at(index.row()).Y);
	
	return QVariant();
}

QVariant ConstantsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(section == 0)
		return "Constant";
	if(section == 1)
		return "Value";
	return "";
}

bool ConstantsModel::setData(const QModelIndex &index, const QVariant &Value, int role)
{
	ConstantsModelPoint point = ConstantValues->takeAt(index.row());
	
	if(index.column() == 0)
	{
		point.X = Value.toString();
		ConstantValues->insert(index.row(), point);
		emit this->layoutChanged();
		return true;
	}
	if(index.column() == 1)
	{		
		point.Y = Value.toDouble();
		ConstantValues->insert(index.row(), point);		
		emit this->layoutChanged();
		return true;
	}	
	return false;
}

Qt::ItemFlags ConstantsModel::flags(const QModelIndex &index)const
{
	if(index.isValid())
		return QAbstractTableModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
	
	return Qt::NoItemFlags;
}

bool ConstantsModel::insertRows(int row, int count, const QModelIndex &parent)
{	
	bool Successful = false;
	if(row < 0 || row > ConstantValues->size())	return false;
	
	this->beginInsertRows(parent, row, row + count - 1);
	for(int i = row; i < row + count; i++)
	{
		ConstantValues->insert(i, ConstantsModelPoint());
		Successful = true;
	}
	this->endInsertRows();
	
	return Successful;
}

bool ConstantsModel::removeRows(int row, int count, const QModelIndex &parent)
{
	bool Successful = false;	
	if(row < 0 || row > ConstantValues->size())	return false;	
	
	this->beginRemoveRows(parent, row, row + count - 1);
	for(int i = row + count - 1; i > row - 1; i--)
	{
		ConstantValues->removeAt(i);
		Successful = true;		
	}	
	this->endRemoveRows();
	
	return Successful;
}

QModelIndex ConstantsModel::index(int row, int column, const QModelIndex &parent) const
{
	if(parent.isValid())
		return QModelIndex();
	return this->createIndex(row, column);
}
