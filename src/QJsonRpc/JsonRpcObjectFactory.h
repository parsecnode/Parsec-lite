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

#include <QByteArray>

class QJsonObject;
class QJsonValue;

namespace QJsonRpc {

class JsonRpcObject;

class JsonRpcObjectFactory {
public:
  static JsonRpcObject* createJsonRpcObject(const QJsonValue& _jsonValue, int& _jsonRpcErrorCode, QString& _jsonRpcErrorString,
    QString& _jsonRpcErrorData);

private:
  static JsonRpcObject* parseJsonRpcObject(const QJsonObject& _jsonObject, int& _jsonRpcErrorCode, QString& _jsonRpcErrorString,
  QString& _jsonRpcErrorData);
};

}
