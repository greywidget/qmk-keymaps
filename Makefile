USER = greywidget
IRIS_FILE = keebio_iris_rev2_$(USER)
IRIS_PATH = iris/$(IRIS_FILE)
$(eval CURRENT_TIME := $(shell date +'%Y%m%d_%H%M%S'))

iris:
	if [ -f $(IRIS_PATH).hex ]; then \
		mv $(IRIS_PATH).hex $(IRIS_PATH)_$(CURRENT_TIME).hex; \
	fi

	rm -rf qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)
	ln -s /Users/kiwi/qmk-keymaps/iris qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)

	qmk compile -kb keebio/iris/rev2 -km $(USER)
	mv qmk_firmware/$(IRIS_FILE).hex iris/$(IRIS_FILE).hex

	rm -rf qmk_firmware/keyboards/keebio/iris/keymaps/$(USER)

.PHONY: iris
