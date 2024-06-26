# SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
#
# SPDX-License-Identifier: LGPL-3.0-or-later

# XDG_DATA_DIRS environment variable maybe be unset by a program
# so we need to set it again

LINGLONG_ROOT="/var/lib/linglong"

new_dirs=
while read -r install_path; do
    share_path=$install_path/entries/share
    case ":$XDG_DATA_DIRS:" in
    *":$share_path:"*) : ;;
    *":$share_path/:"*) : ;;
    *) new_dirs=${new_dirs:+${new_dirs}:}$share_path ;;
    esac
done <<EOF
	${XDG_DATA_HOME:-"$HOME/.local/share"}/linglong
	${LINGLONG_ROOT}
EOF

XDG_DATA_DIRS="${new_dirs:+${new_dirs}:}${XDG_DATA_DIRS:-/usr/local/share:/usr/share}"
export XDG_DATA_DIRS="$XDG_DATA_DIRS"
