#!/bin/bash

# Author  : Gustavo Bacagine <gustavo.bacagine@protonmail.com>
# License : GPLv2
# Site    : https://fatecpkg.github.io

#######################################################
#                      Bibliotecas
#######################################################

# Carrega bibliotecas necessárias
# para o funcionamento do fatec
includes=(
	'/etc/fatec/fatec.conf'
	'/usr/libexec/fatec/core.sh'
	'/usr/libexec/fatec/help.sh'
)
for include_load in "${includes[@]}"; do
	source "$include_load" || { echo "ERROR ON LOAD \"$include_load\", ABORT"; exit 1; }
done

#####################################################
#                     Diretorios Especiais
#####################################################
dirlist='/var/lib/fatec/list'     # Lista do pacote 'pack.list'
dirdesc='/var/lib/fatec/desc'     # Descrição do pacote 'pack.desc'
dirremove='/var/lib/fatec/remove' # Script de remoção do pacote 'rm.sh'

# Impede que usuários comuns 
# usam o gerencador
[[ "$UID" -ne '0' ]] && { echo "Root is required"; exit 1; }


