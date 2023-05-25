USER = greywidget
IRIS_FILE = keebio_iris_rev2_$(USER)
IRIS_PATH = iris/$(IRIS_FILE)

ROMAC_FILE = kingly_keys_romac_$(USER)
ROMAC_PATH = romac/$(ROMAC_FILE)

KYRIA_REV1_FILE = splitkb_kyria_rev1_$(USER)
KYRIA_REV1_PATH = kyria-1/$(KYRIA_REV1_FILE)

$(eval CURRENT_TIME := $(shell date +'%Y%m%d_%H%M%S'))

iris:
	if [ -f $(IRIS_PATH).hex ]; then \
		mv $(IRIS_PATH).hex $(IRIS_PATH)_$(CURRENT_TIME).hex; \
	fi

	rm -rf qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)
	ln -s /Users/kiwi/qmk-keymaps/iris qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)

	qmk compile -kb keebio/iris/rev2
	mv qmk_firmware/$(IRIS_FILE).hex iris/$(IRIS_FILE).hex

	rm -rf qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)

romac:
	if [ -f $(ROMAC_PATH).hex ]; then \
		mv $(ROMAC_PATH).hex $(ROMAC_PATH)_$(CURRENT_TIME).hex; \
	fi

	rm -rf qmk_firmware/keyboards/kingly_keys/romac/keymaps/$(USER)
	ln -s /Users/kiwi/qmk-keymaps/romac qmk_firmware/keyboards/kingly_keys/romac/keymaps/$(USER)

	qmk compile -kb kingly_keys/romac
	mv qmk_firmware/$(ROMAC_FILE).hex romac/$(ROMAC_FILE).hex

	rm -rf qmk_firmware/keyboards/kingly_keys/romac/keymaps/$(USER)

kyria-1:
	if [ -f $(KYRIA_REV1_PATH).hex ]; then \
		mv $(KYRIA_REV1_PATH).hex $(KYRIA_REV1_PATH)_$(CURRENT_TIME).hex; \
	fi

	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/$(USER)
	ln -s /Users/kiwi/qmk-keymaps/kyria-1 qmk_firmware/keyboards/splitkb/kyria/keymaps/$(USER)

	# qmk compile -e CONVERT_TO=promicro_rp2040 -kb splitkb/kyria/rev1 -km $(USER)
	qmk compile -kb splitkb/kyria/rev1
	mv qmk_firmware/$(KYRIA_REV1_FILE).hex kyria-1/$(KYRIA_REV1_FILE).hex

	rm -rf qmk_firmware/keyboards/splitkb/kyria/keymaps/$(USER)

.PHONY: iris kyria-1 romac
