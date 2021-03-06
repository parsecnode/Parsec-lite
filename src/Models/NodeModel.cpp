// Copyright (c) 2011-2015 The Cryptonote developers
// Copyright (c) 2015 XDN developers
// Copyright (c) 2016-2018 Parsec developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <QUrl>

#include "NodeModel.h"
#include "Settings/Settings.h"

namespace WalletGui {

NodeModel::NodeModel(QObject* _parent) : QStringListModel(_parent) {
  setStringList(Settings::instance().getRemoteNodeList());
}

NodeModel::~NodeModel() {
}

void NodeModel::addNode(const QUrl& _url) {
  insertRow(rowCount());
  setData(index(rowCount() - 1, 0), QString("%1://%2:%3").arg(_url.scheme()).arg(_url.host()).arg(_url.port()));
}

QVariant NodeModel::data(const QModelIndex& _index, int _role) const {
  if (!_index.isValid()) {
    return QVariant();
  }

  switch (_role) {
  case ROLE_HOST:
    return QUrl::fromUserInput(stringList()[_index.row()]).host();
  case ROLE_PORT:
    return QUrl::fromUserInput(stringList()[_index.row()]).port();
  default:
    break;
  }

  return QStringListModel::data(_index, _role);
}

Qt::ItemFlags NodeModel::flags(const QModelIndex& _index) const {
  return (Qt::ItemIsEnabled | Qt::ItemNeverHasChildren | Qt::ItemIsSelectable);
}

QVariant NodeModel::headerData(int _section, Qt::Orientation _orientation, int _role) const {
  if (_orientation != Qt::Horizontal || _role != Qt::DisplayRole) {
    return QVariant();
  }

  return tr("Node URL");
}

bool NodeModel::setData(const QModelIndex& _index, const QVariant& _value, int _role) {
  bool res = QStringListModel::setData(_index, _value, _role);
  Settings::instance().setRemoteNodeList(stringList());
  return res;
}

}
