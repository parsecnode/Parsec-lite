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

#include "CopyMagicLabel.h"
#include "Settings/Settings.h"
#include "Style/Style.h"

namespace WalletGui {

namespace {

const char COPY_MAGIC_LABEL_STYLE_SHEET_TEMPLATE[] =
  "* {"
    "font-family: %fontFamily%;"
  "}"

  "WalletGui--CopyMagicLabel {"
    "color: %fontColorGreen%;"
    "font-size: %fontSizeSmall%;"
  "}";

}

CopyMagicLabel::CopyMagicLabel(QWidget* _parent) : MagicLabel(_parent) {
  setStyleSheet(Settings::instance().getCurrentStyle().makeStyleSheet(COPY_MAGIC_LABEL_STYLE_SHEET_TEMPLATE));
}

CopyMagicLabel::~CopyMagicLabel() {
}

}
