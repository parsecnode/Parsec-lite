// Copyright (c) 2015-2017, The Bytecoin developers
// Copyright (c) 2022, Parsec Node
//
// This file is part of Parsec.
//
// Parsec is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Parsec is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Parsec.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <QAbstractItemModel>

namespace WalletGui {

class ICryptoNoteAdapter;

class TransfersModel : public QAbstractItemModel {
  Q_OBJECT
  Q_DISABLE_COPY(TransfersModel)
  Q_ENUMS(Columns)

public:
  enum Columns {
    COLUMN_ADDRESS = 0, COLUMN_AMOUNT, COLUMN_PROOF
  };

  enum Roles {
    ROLE_ADDRESS = Qt::UserRole, ROLE_AMOUNT, ROLE_PROOF, ROLE_TYPE, ROLE_ICON, ROLE_IS_DONATION_TRANSFER
  };

  TransfersModel(ICryptoNoteAdapter* _cryptoNoteAdapter, const QModelIndex& _transactionIndex, QObject* _parent);
  ~TransfersModel();

  // QAbstractItemModel
  Qt::ItemFlags flags(const QModelIndex& _index) const override;
  int columnCount(const QModelIndex& _parent = QModelIndex()) const override;
  int rowCount(const QModelIndex& _parent = QModelIndex()) const override;
  QVariant headerData(int _section, Qt::Orientation _orientation, int _role = Qt::DisplayRole) const override;
  QVariant data(const QModelIndex& _index, int _role = Qt::DisplayRole) const override;
  QModelIndex index(int _row, int _column, const QModelIndex& _parent = QModelIndex()) const override;
  QModelIndex parent(const QModelIndex& _index) const override;

private:
  ICryptoNoteAdapter* m_cryptoNoteAdapter;
  QPersistentModelIndex m_transactionIndex;
  const int m_columnCount;

  QVariant getDisplayRole(const QModelIndex& _index) const;
  QVariant getDecorationRole(const QModelIndex& _index) const;
  QVariant getToolTipRole(const QModelIndex& _index) const;
  QVariant getUserRole(const QModelIndex& _index, int _role) const;
};

}
