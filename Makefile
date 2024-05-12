USER = greywidget
IRIS_FILE = keebio_iris_rev2_$(USER)
IRIS_PATH = iris/$(IRIS_FILE)

ROMAC_FILE = kingly_keys_romac_$(USER)
ROMAC_PATH = romac/$(ROMAC_FILE)

KYRIA_REV1_FILE = splitkb_kyria_rev1_$(USER)
KYRIA_REV1_PATH = kyria-1/$(KYRIA_REV1_FILE)

KYRIA_REV3_FILE = splitkb_kyria_rev3_$(USER)_elite_pi
KYRIA_REV3_PATH = kyria-3/$(KYRIA_REV3_FILE)

$(eval CURRENT_TIME := $(shell date +'%Y%m%d_%H%M%S'))

iris:
	rm -rf qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)
	ln -s /Users/kiwi/qmk-keymaps/iris qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)

	qmk compile -kb keebio/iris/rev2
	mv qmk_firmware/$(IRIS_FILE).hex iris/$(IRIS_FILE)_$(CURRENT_TIME).hex

	rm -rf qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)

romac:
	rm -rf qmk_firmware/keyboards/kingly_keys/romac/keymaps/$(USER)
	ln -s /Users/kiwi/qmk-keymaps/romac qmk_firmware/keyboards/kingly_keys/romac/keymaps/$(USER)

	qmk compile -kb kingly_keys/romac
	mv qmk_firmware/$(ROMAC_FILE).hex romac/$(ROMAC_FILE)_$(CURRENT_TIME).hex

	rm -rf qmk_firmware/keyboards/kingly_keys/romac/keymaps/$(USER)

kyria-1:
	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/$(USER)
	ln -s /Users/kiwi/qmk-keymaps/kyria-1 qmk_firmware/keyboards/splitkb/kyria/keymaps/$(USER)

	qmk compile -kb splitkb/kyria/rev1
	mv qmk_firmware/$(KYRIA_REV1_FILE).hex kyria-1/$(KYRIA_REV1_FILE)_$(CURRENT_TIME).hex

	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/$(USER)

kyria-3:
	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/$(USER)
	ln -s /Users/kiwi/qmk-keymaps/kyria-3 qmk_firmware/keyboards/splitkb/kyria/keymaps/$(USER)

	qmk compile -e CONVERT_TO=elite_pi -kb splitkb/kyria/rev3
	mv qmk_firmware/$(KYRIA_REV3_FILE).uf2 kyria-3/$(KYRIA_REV3_FILE)_$(CURRENT_TIME).uf2

	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/$(USER)

.PHONY: iris kyria-1 kyria-3 romac
