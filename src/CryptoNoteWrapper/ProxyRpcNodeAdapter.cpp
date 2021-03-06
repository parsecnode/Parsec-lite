// Copyright (c) 2015-2017, The Bytecoin developers
// Copyright (c) 2017-2020, The Parsec developers
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

#include "ProxyRpcNodeAdapter.h"
#include "ProxyRpcNodeWorker.h"
#include "WalletGreenAdapter.h"

namespace WalletGui {

ProxyRpcNodeAdapter::ProxyRpcNodeAdapter(const CryptoNote::Currency& _currency,
                                         Logging::ILogger& _loggerManager, Logging::ILogger& _walletLogger,
                                         const QUrl& _nodeUrl, QObject* _parent) :
    CommonNodeAdapter(_parent), m_currency(_currency), m_loggerManager(_loggerManager),
    m_walletLogger(_walletLogger), m_nodeUrl(_nodeUrl) {
}

ProxyRpcNodeAdapter::~ProxyRpcNodeAdapter() {
}

INodeAdapter* ProxyRpcNodeAdapter::createWorker() const {
  return new ProxyRpcNodeWorker(m_currency, m_loggerManager, m_walletLogger, m_nodeUrl, nullptr);
}

}
