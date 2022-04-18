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

#include <QSortFilterProxyModel>

namespace WalletGui {

class FilteredByHashTransactionsModel : public QSortFilterProxyModel {
  Q_OBJECT
  Q_DISABLE_COPY(FilteredByHashTransactionsModel)

public:
  explicit FilteredByHashTransactionsModel(QObject* _parent);
  ~FilteredByHashTransactionsModel();

  void setFilter(const QString& _hash);

protected:
  virtual bool filterAcceptsRow(int _sourceRow, const QModelIndex& _sourceParent) const override;

private:
  QString m_hash;
};

}
